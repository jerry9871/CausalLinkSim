#include <math.h>
#include <SDL3/SDL.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define NPARTICLES 5
#define CAUSAL_LINK_LENGTH  1500

struct causal_link {
	int length;
	double last_distance;
	double m;
	double mx[CAUSAL_LINK_LENGTH];
	double my[CAUSAL_LINK_LENGTH];

	double mr[CAUSAL_LINK_LENGTH];
};

struct particle {
	double x;
	double y;
	double dx;
	double dy;
	double ax;
	double ay;
	double charge;
	double mass;

	//vis
	double em;

	//zero index defines the moment when the information reaches the particle
	struct causal_link links[NPARTICLES];

} particles[NPARTICLES];


int
init_scene1()
{
	memset(particles, 0, sizeof(particles));

	double x = 0, y = 0;

	for (int i = 0; i < NPARTICLES; i++) {
		//particles[i].dx = 0.003 * ((rand() % 90) - 45);
		//particles[i].dy = 0.003 * ((rand() % 90) - 45);

		int marginx = WINDOW_WIDTH / 3;
		int marginy = WINDOW_HEIGHT / 3;

		particles[i].x = marginx + (rand() % (WINDOW_WIDTH - 2 * marginx));
		particles[i].y = marginy + (rand() % (WINDOW_HEIGHT - 2 * marginy));

		//particles[i].x = 10 + (x * (double)(WINDOW_WIDTH - 20));
		//particles[i].y = 10 + (y * (double)(WINDOW_HEIGHT - 20));

		x += 0.06;

		if (x > 1) {
			x = 0;
			y += 0.06;
		}

		double me = 0.01;
		//The proton-to-electron mass ratio is approximately 1,836.15. This means a proton is about 1,836 times more massive than an electron, despite having the same magnitude of electric charge.
		particles[i].charge = (i & 1) ? 1 : -1;
		particles[i].mass = me; //(i & 1) ? (me / 1836) : me;
	}

#define WIGGLING 1

	for (int i = 0; i < WIGGLING; i++) {
		particles[i].y = WINDOW_HEIGHT / 2;
		particles[i].x = 8 * i + WINDOW_WIDTH / 2;

		//particles[i].mass = 0.1;
	}

}

int
main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool quit = false;
	SDL_Event event;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	// Create window
	window = SDL_CreateWindow("Causal link simulator", WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	if (!window) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, NULL);

	if (!renderer) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	init_scene1();

	int show_links = 0;
	int show_actions = 1;
	int show_es = 0;
	int show_em = 1;
	double x = 0, y = 0;

	// Main loop
	while (!quit) {
		// Process events first
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT)
				quit = true;

			else if (event.type == SDL_EVENT_KEY_DOWN)

				// Handle key press
				switch (event.key.key) {
					case SDLK_RIGHT:
						for (int i = 0; i < WIGGLING; i++)
							particles[i].x ++; //sin(x);

						x += 1.7;
						break;

					case SDLK_LEFT:
						for (int i = 0; i < WIGGLING; i++)
							particles[i].x --; //sin(x);

						x += 0.1;
						break;

					case SDLK_UP:
						for (int i = 0; i < WIGGLING; i++)
							particles[i].y --; // = sin(x);

						x += 0.7;
						break;

					case SDLK_DOWN:
						for (int i = 0; i < WIGGLING; i++)
							particles[i].y ++; // = sin(x);

						x += 0.1;
						break;

					case SDLK_SPACE:
						show_links ++;
						show_links %= 3;
						break;

					case SDLK_RETURN:
						show_actions = !show_actions;
						break;

					case SDLK_E:
						show_es = !show_es;
						break;

					case SDLK_M:
						show_em = !show_em;
						break;
				}
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		double dt = 1;

		//iterate through e every particle
		for (int i = 0; i < NPARTICLES; i++) {

			struct particle* p = &particles[i];
			double ax = 0, ay = 0, ix = 0, iy = 0;

			//iterate through every linked particle and advance causal links
			for (int j = 0; j < NPARTICLES; j++) {

				if (j == i)
					continue;

				struct particle* q = &particles[j];

				if (q->charge == 0)
					continue;

				double diffx = q->x - p->x;
				double diffy = q->y - p->y;
				double distance = sqrt(diffx * diffx + diffy * diffy);

				if (distance >= CAUSAL_LINK_LENGTH - 2)
					continue;

				struct causal_link* l = &p->links[j];

				// TODO replace with variable length fifo

				for (int k = 0; k < l->length + 2; k++) {

					//in 3D, coulomb force decreases with second order hyperbolic: 1/x^2, for example:
					//1/1, 1/4, 1/9, 1/16, 1/25, 1/36, 1/49, 1/64, ...
					//our favorite exponential decay is faster:
					//1/1, 1/2, 1/4, 1/8, 1/16, 1/32, 1/64, 1/128, ...

					//assume in 2D plane, coulomb force should decrease with 1/x (2D projection). generate hyperbolic decay:
					/*  double q = distance - k;

					    if(q > 0)
					     q = (q+20) / (q + 21);

					    //if the distance became shorter, we need to "aggregate" the previous actions
					    //just shift them
					    else
					     q = 1;

					    //second order hyperbolic
					    //q*=q;

					    //q = 0.95;

						l.mx[k] = l.mx[k + 1] * q;
						l.my[k] = l.my[k + 1] * q;
					*/

					l->mx[k] = l->mx[k + 1];
					l->my[k] = l->my[k + 1];
					l->mr[k] = l->mr[k + 1];

					if (k >= distance || !show_links)
						continue;

					//link visualization (very consuming)
					double tx = l->mx[k];
					double ty = l->my[k];

					//if (q->charge < 0)
					//tx = -tx, ty = -ty;

					double d = sqrt(tx * tx + ty * ty);
					tx = p->x + k * tx / d;
					ty = p->y + k * ty / d;

					if (show_links == 1) {
						double c1 = d * 10000;
						double c2 = d * 5000;

						if (c1 > 255)
							c1 = 255;

						if (c2 > 255)
							c2 = 255;

						if (p->charge * q->charge > 0)
							SDL_SetRenderDrawColor(renderer, c1, c2, c2, 255);

						else
							SDL_SetRenderDrawColor(renderer, c2, c2, c1, 255);

					} else {
						d  = fabs(l->mr[k]);

						double c1 = d * 200;
						double c2 = d * 100;

						if (c1 > 255)
							c1 = 255;

						if (c2 > 255)
							c2 = 255;

						if (l->mr[k] > 0)
							SDL_SetRenderDrawColor(renderer, c1, c2, c2, 255);

						else
							SDL_SetRenderDrawColor(renderer, c2, c2, c1, 255);
					}

					SDL_RenderPoint(renderer, tx,  ty);
				}

				// dynamically set next length of propagation to calculate. TODO replace with scalable FIFO
				l->length --;

				if (distance > --l->length)
					l->length = distance;

				//calculate the rate of action delivery
				if (l->last_distance == 0)
					l->last_distance = distance;

				double rate = distance - l->last_distance;

				l->last_distance = distance;

				// Scale action in 2D space.
				// Note that dividing by distance presumes immediate knowleedge of the distance,
				// which is not the case in a relativistic world. That's why we tried to dissipate the action along the causal link.
				diffx /= distance * distance;
				diffy /= distance * distance;

				// scale action according to the property
				diffx *= q->mass;
				diffy *= q->mass;

				// spread insertion across two buffer spaces
				int index = distance;
				distance -= index;

				l->mx[index] += diffx * (1 - distance);
				l->my[index] += diffy * (1 - distance);
				l->mr[index] += rate * (1 - distance);
				l->mx[index + 1] += diffx * distance;
				l->my[index + 1] += diffy * distance;
				l->mr[index + 1] += rate * distance;

				//extract resulting action from end of causal link (average across two closest actions)
				double tx = (l->mx[0] + l->mx[1]) / 2;
				double ty = (l->my[0] + l->my[1]) / 2;
				double tf = (l->mr[0] + l->mr[1]) / 2;

				double d = sqrt(tx * tx + ty * ty);

				if (d == 0)
					continue;

				//initialize link momentum if not set
				if (!l->m)
					l->m = d;

				//accumulate inertial coupling (without tf)
				//ix -= (d - l->m) * tx / d / p->mass;
				//iy -= (d - l->m) * ty / d / p->mass;


				ix -= tx * (1 - l->m / d) / p->mass;
				iy -= ty * (1 - l->m / d) / p->mass;





				//accumulate inertial coupling
				//ix += (tf * tx / d) * 0.5;
				//iy += (tf * ty / d) * 0.5;

				//accumulate action
				//ax += tx;
				//ay += ty;
			}

			//calculate resulting action force
			ax *= p->charge;
			ay *= p->charge;

			if (0) {
				//integrate force into speed
				p->dx -= ax * dt * p->mass;
				p->dy -= ay * dt * p->mass;

				//hard-limit the speed to speed of causality (absolute frame - get rid of!)
				//TODO figure out how inertia works !
				double sp = sqrt(p->dx * p->dx + p->dy * p->dy);

				double max_speed = 0.5;

				if (sp > max_speed) {
					p->dx *= max_speed / sp;
					p->dy *= max_speed / sp;
				}

				//damping
				// p->dx -=  p->dx * 0.001;
				// p->dy -=  p->dy * 0.001;

				//integrate speed into position (absolute frame - get rid of!)
				//TODO figure out how inertia works !
				p->x += p->dx * dt;
				p->y += p->dy * dt;

			} else {

				//attempt to reduce order - does inertia emerge?
				//p->x += p->ax * dt * p->inertia * 1000 * ix;
				//p->y += p->ay * dt * p->inertia * 1000 * iy;

				//propagate the particle along inertial coupling base
				p->x += ix;
				p->y += iy;

				//the causal link should deliver the action to the particle.

				/*
					Here is not good point to process inertia. If someone bounces the particle lacally, it will not immediately see the effect from incoming causal links.
					We need to see immediate local inertia to emerge. Suggestion: The particle has to deliver its momentum to the causal links and move accordingly.
					But that would violate the causality principle?
				*/
			}

			//calculate magnitude (electrostatic force)
			double es = sqrt(ax * ax + ay * ay);

			//calculate angle change (field rotation : magnetic force)
			double em = (ax - p->ax) * ay -
						(ay - p->ay) * ax;
			p->ax = ax;
			p->ay = ay;

			//filter for visualization
			p->em += (em - p->em) * 0.2;

			//handle collisions to the walls
			int margin = 1;

			if (p->x < margin)
				p->x = margin, p->dx *= -1;

			if (p->x > WINDOW_WIDTH - margin - 1)
				p->x = WINDOW_WIDTH - margin - 1, p->dx *= -1;

			if (p->y < margin)
				p->y = margin, p->dy *= -1;

			if (p->y > WINDOW_HEIGHT - margin - 1)
				p->y = WINDOW_HEIGHT - margin - 1, p->dy *= -1;

			//draw particle now
			if (p->charge > 0)
				SDL_SetRenderDrawColor(renderer, 255, 128, 128, 255);

			else
				SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);

			SDL_FRect rect = {p->x - 1, p->y - 1, 3, 3};
			SDL_RenderFillRect(renderer, &rect);


			double scale = 100;

			// draw total resulting force
			if (show_actions)
				SDL_RenderLine(renderer, p->x, p->y, p->x - ax * scale, p->y - ay * scale);

			// draw electrostatic force
			if (show_es) {
				double e = es * scale;
				SDL_FRect rect = {p->x - e / 2, p->y - e / 2, e, e};
				SDL_RenderFillRect(renderer, &rect);
			}

			// draw magnetic field lines with circle (perpendicular to the simulation plane)
			if (show_em) {
				double e = sqrt(fabs(p->em) * 1000000000);

				if (e > 0) {
					if (e > 255)
						e = 255;

					if (p->em > 0)
						SDL_SetRenderDrawColor(renderer, e, 0, 0, 255);

					else
						SDL_SetRenderDrawColor(renderer, 0, 0, e, 255);

					//draw a circle here
					double x = 5, y = 0;

					for (int i = 0; i < 31; i ++) {
						SDL_FRect rect = {p->x + x, p->y + y, 2, 2};
						SDL_RenderFillRect(renderer, &rect);

						x += y * 0.2;
						y -= x * 0.2;

					}
				}
			}
		}

		// Present the rendered image
		SDL_RenderPresent(renderer);
	}

// Clean up
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
