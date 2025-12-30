# CausalLinkSim

This humble particle simulator aspires to demonstrate some physical laws as emergent properties from a few, simple interaction principles.

## How to build and run (Windows)

- Clone the repository
- Install minGW-w64 with MSYS2 and SDL3 packages
- Go to the folder and type `make`
- Run `particle.exe` to start

## Motivation

I am neither physicist, nor mathematician, I am just an engineer. Yet I like excercising reductionism and I share the belief that world should be reducible to a minimal set of rules - abd finding the proper formalism is the key. In my view, the current mainstream theoretical physics is based on outdated premises, keeps trying to break trhough with far too complex mathematical constructs, deviates from experimental verifiability and produces intuition-violating confusions, misunderstandings and paradoxes.

Rather than extending the existing high-level theories, I am trying to build a simple model of the universe from scratch-with engineer's approach. I am not trying to prove or disprove anything, just to see if I can get some of the well-known physical laws as emergent properties from a minimal set of simple rules.

## Inspirations and philosophical principles behind

Recently, I noticed emerging neo-Lorentzian theories (Independent Physics group, Dialect, etc. showed compelling intuitive ways how to explain relativistics effects with aether. They even seem to suceed to combine GR with Aether / curved / flowing space). The key insight is that once broken down, these aren't really competing physical theories - they're different interpretations of the same mathematical framework. Believing or not believing in Aether is therefore a matter of choice as it can not be proven / disproven experimentaly, at least for now. This project aligns with the process philosophy tradition and relational approaches to physics. Rather than aether, I choose **relationality and causality** as a fundaments for my model. I start from a postulate that the existence is relational. Whatever exists _has to_ interact with something else, and that is the very definition of existence. I furthermore state that the relation is directional and causal, meaning that the existence of a single component of reality can influence another and vice versa. Entities that do not fulfill these criteria would be excluded from reality. The next postulate is that the causality propagation forms a metric of what we perceive as space-time container. There have been many attempts to refute space-time as being fundamental, with varying adherance to rigorosity / philosophical belief. I got inspirations from:

- **Felix Finster's causal fermion systems** - reverses the attempt of trying to fit wave functions and quantum operators into space-time, but states that the wave functions are ontological primitives and space-time is emergent. In his theory, fermions (massive particles subjected to Pauli's exclusion principle) are fundamental building blocks of reality, and their causal interaction produces the space-time container. This is very similar to what I am trying to show here (emerge spacetime from causal interaction between entities), but, he is a rigorous mathematician and he starts with quantum theory postulates. I will not attempt to pretend to understand his work. I will ultimately hope to emerge some quantum effects from discrete computations in my model.

- **Stephen Wolfram's Wolfram Physics project** - he disputes that the universe must follow rules described by differential equations and suggests that the base of reality may be computation. He creates a concept of 'ruliad' which is a set of all possible computational rules and arguments about computational irreducibility is responsible for phenomenons such as entropy, free will, disputing superdeterminism and so on. He frequently uses expressions such as "universe updates itself" and so on. On top of those postulates he builds a causal hypergraph from which the space time emerges. I will again not attempt to pretent to understand deeply what he is doing, I just adhere to the idea that the universe may not be governed by continuous differential equations.

- **Philosophy streams** - I like the relativists, process philosophy and putting information at the core of reality. Alfred North Whitehead and 'event' based reality, Ernst Mach and hypothesis that inertia is not intrinsic, or John Wheeler and 'it from bit'. Recent idealists worth noting pioneered by Alan Watts, Bernardo Kastrup, Donald Hoffmann, and philosophers of physics such as Jonathan Fay, or Jacob Barandes.

The simulation is built around my idea of replacing **fields** in physics with **causal links**. A "field" of any kind requires its own, usually independent reference frame and a metric in spacetime. I am reversing the order, and state that the field descriptions (requiring an objective metrics) and their reference frames are emergent. I define the causal link is an unilateral coupling relation along which the interaction propagates. An aggregate of all adjacent causal links will be called the **light cone**. An entity, or a **particle** is a potentiality, that manifests itself into physical existence.

## The distilled postulates (and resulting disputes)

As the model fundaments, I choose:

- **relationality** Every entity manifests its existence by exchanging information with other entities. Three-dimensional space emerges from the causal coupling between entities and is the observable metric emerging from the NxN causal link network. Time is a local phenomenon and a **complementary metric**, necessary to define update continuity in causal propagation.
- **causality** Each entity constatnly receives discrete information from coupled entities (at a constant "speed", perceived as local time accumulation, in its own reference frame), actualizes itself and then broadcasts its actualized state towards other coupled entities.

Resulting philosophical disputes of mainstream representation:

- **Time is not a dimension**, but a local metric necessary to define update continuity in causal propagation.
- **The "field" is a mathematical construct**, not ontologically grounded. It is defined as a potentiality for interaction and it's prevalent usage in current physics yields to confusions, as no other existential proof of a "field" has been shown other than through potentiality for interaction, therefore, not granting any more ontological grounding to the field than to my causal link.
- **Block universe in GR is a mathematical construct**, not ontologically grounded. The future and past does not exist simultaneously, neither the observer-dependent 'slice of simultaneity' does. Space and time manifests itself locally, as a present moment - result of evolution of the causal, informational influence aggregates for every coupled entity.

## Expected outcomes (wish list)

In the following sections, I will describe the expected simulation outcomes within different physical contextes. The list is not exhaustive and I am open to any suggestions. Everything is written from hands-on engineer's perspective, so please excuse me if I am using improper terminology, mixing things up or minsunderstanding some of the concepts.

### Must have: ELECTROMAGNETISM and SPECIAL RELATIVITY

- Electrostatic force is a (quasi-fundamental) property of the particle and its charge (Gauss's law) and the action quanta are distributed across causal links (my claim).
- Length contraction is emergent phenomena observed within the massive particles and their causal interactions, due to the advanced/retarded interaction delivery along the causal links.
- The Lorentz invariance (statement that fundamental laws are the same for all inertial observers) is implicit, since we do not require any reference frame and / or the field to propagate in. The causal link speed is isotropic in the frame reference of the receiver entity.
- A light clock moving at constant speed relative to a stationary observer will appear to tick slower due to advanced/retarded wavefront delivery along the causal links. Within the Twin paradox concept, the total tick count accumulated by a non-inertial clock will be less than the stationary clock at reunion, as predicted by the conventional theory. This is due to the combined effect of advanced/retarded wavefront and the inertial coupling (to be shown). A hint can be found in the Dialect video, where they demonstrated that twin paradox can be explained without the need for isotropy of the speed of light, effectively demonstrating that the Lorentz's Original Ether Theory is sufficient to explain the effect.
- Length contraction is complementary to the time dilation. **The space scaling anisotropy should yield to time speed anisotropy.** - TODO interpret this properly.
- Magnetism is the time rotation of the electrostatic force vector manifested on a charged particle, when observed as contribution from every nearby moving charged particle (Faraday's law in simple terms) - TODO verify if this reflect's to the actual law and if contribution from every single charged particle yields to the law VS the epxlanation using relativistic length contraction
- Light and other electromagnetic waves are emergent properties of the particles and their causal interactions. The combined effect of vector actions propagating along advanced/retarded causality wavefront yields to the perpendicular electric and magnetic propagating fields along null trajectories.

### Nice to have: GRAVITY, INERTIA, and forces in ROTATING REFERENCE FRAME

- I adhere to Mach's principle: The inertia of a particle is determined by the distribution of all other particles in the universe, in both senses: (1) inertial constant motion and (2) inertial forces. The Foucault pendulum and Newton's bucket experiment will show relative to the distant stars (argued by Mach), not to an absolute (curved/flat) space (suggested by Newton).
- Inertia, as the resistance to acceleration, is ultimately postulated, and not derived in nearly all mainstream theories up to this day. I would like to show that inertia is an emergent phenomenon from the particles and their interactions. Particles are **inertially coupled** to each other with finite "speed" of causality.
- Inertial coupling is not scalar, but vectorial; otherwise "a spinning skater wouldn't feel the centrifugal force". It wouldn't be possible to explain the Coriolis effect, which is also a result of the inertial coupling.
- I believe that so called "anisotropic inertia", resulting from Machian gravity models, is to be expected, because distribution of inertial potential is corellated with the space curvature - therefore, the measurement apparatus is covariant with the strength of inertia and "stretching/density" of emergent spacetime. This was argued by Dicke and is relevant to the variable gravitational constant in Brans-Dicke theory of gravity.
- The claim of GR that spacetime geometry becomes flat Minkowski spacetime far from massive objects is to be questioned. The stress tensor and cosomological constant may be ill defined (my claim). The further away from the massive objects, the further the stretching of the causal links and the lesser the inertial coupling. The spacetime geometry is only flat as long as the matter distribution is homogeneous. Flatness of spacetime and the homogeneity of matter are complementary. Philosophically I believe that without matter, there is no space, therefore matter "generates space", rather than "bends space" as claimed in GR.
- Dark matter and dark energy are apparent and the observed discrepancies stems from misunderstandings of how inertia and gravity works and from the questioned presumption of the flat Minkowski spacetime geometry.
- Sky Darmos claims that the gravity constant is not proportional to the mass, but to the number of particles. Can that be relevant for this attempt?
- In SR, momentum and energy are frame-dependent; rest mass is invariant. Therefore, each causal link has it's own momentum-like equivalent state. State vector is a property the causal link, rather than of the particle itself. (TODO -verify this claim - depends on the final implementation!)

#### Inertia & Gravity merger (inspired by https://jonathanfay.com and https://derprimer.de/gravinertia/)

"Mach’s principle requires that only relative quantities are included in the describing equations." Schrodinger (1925) was first to write the Lagrangian of any two interacting particles and for the universe:

$$L_{ij} = \delta \frac{m_i m_j}{r_{ij}c^2} \dot{r}_{ij}^2 - \frac{m_i m_j}{r_{ij}}, \qquad L = \sum_{i < j} \left( \frac{\delta m_i m_j}{c^2 r_{ij}} \dot{r}_{ij}^2 - \frac{m_i m_j}{r_{ij}} \right)$$

In the most simplistic example, the equation of motion for the radial separation $r$ in single particle pair is:

$$\ddot{r} = \frac{1}{2r} \left( \dot{r}^2 + \frac{c^2}{\delta} \right)$$

To get a full motion equations, we need to solve the **Euler-Lagrange equation** for particle $i$:

$$\frac{d}{dt} \underbrace{ \left( \frac{\partial L}{\partial \mathbf{v}_i} \right)}_{\text{Momentum } \mathbf{P}_i} = \underbrace{\frac{\partial L}{\partial \mathbf{r}_i}}_{\text{Generalized Force}}$$

Let's define the geometry before differentiation:

- Vector distance: $\mathbf{r}_{ij} = \mathbf{r}_i - \mathbf{r}_j$
- Unit vector: $\hat{\mathbf{n}}_{ij} = \frac{\mathbf{r}_{ij}}{r_{ij}}$ (Points from $j$ to $i$)
- Relative Velocity: $\mathbf{v}_{ij} = \mathbf{v}_i - \mathbf{v}_j$
- Radial Velocity scalar: $\dot{r}_{ij} = \hat{\mathbf{n}}_{ij} \cdot \mathbf{v}_{ij}$

Using the chain rule: $\frac{\partial (\dot{r}_{ij}^2)}{\partial \mathbf{v}_i} = 2 \dot{r}_{ij} \frac{\partial \dot{r}_{ij}}{\partial \mathbf{v}_i}$ and from our geometric definition, $\frac{\partial \dot{r}_{ij}}{\partial \mathbf{v}_i} = \hat{\mathbf{n}}_{ij}$, we derive the momentum:

$$\mathbf{P}_i = \sum_{j \neq i} \left( \frac{2\delta m_i m_j}{c^2 r_{ij}} \dot{r}_{ij} \right) \hat{\mathbf{n}}_{ij}$$

**Physical Meaning:** The momentum of particle $i$ is a sum of vectors pointing along the lines to all other particles $j$, weighted by how fast they are moving towards/away from each other.

Step C: The Time Derivative ($\frac{d}{dt} \mathbf{P}_i$) ...

### Super nice to get: GENERAL RELATIVITY

- GR introduces 4D spacetime manifold defined by mass distribution, as a powerful model to evaluate observer-independent spacetime intervals, describe evolution through worldlines and motion of objects through geodesics. However, since time is the foruth dimension in this manifold, many paradoxes arise, such as the idea of static, block universe where past, present and future are equivalent. The "arrow of time" is not rooted in this model. See for exp. "the Andromeda paradox" and it's observer-dependent simultaneity confusion. I postulate that the time is not a coordinate, it is the causality metric of space. Accepting time as "emergence" and purely local phenomenon, devoiding from the block universe and from the necessity to accept observer-dependent simultaneity, I can show that replacing 4D spacetime manifold with 3D space-space manifold preserves the GR effects:

  - In GR, **Volumetric scale of space times Scale of time = 1**, which is true at least for any arbitrary, non-rotating Schwarzchild metric, meaning that space scale is enough to preserve the causality metric of time, and vice versa. This is analogous to the situation in SR, where the length contaction is complementary to the time dilation.

  $$\text{Scale of time} \times \text{Scale of space} = \sqrt{1 - \frac{2GM}{r}} \cdot \frac{1}{\sqrt{1 - \frac{2GM}{r}}} = 1.$$

  - Time dilation is the result of compressed space around massive objects, which causes the local particles to move slower from external observer's perspective. Even the cesium resonator has to cover different amount of space in each oscillation period in stretched/compresssed space, therefore, the ticking will appear to run at different rate to a distant observer.
  - Inertia (resistence to change motion) is axiomatically the resistence towards locally perceived space compression in the direction of acceleration. The compression gradient around massive objects is perceived as acceleration (version of the Einstein's equivalence principle). These gravitational effects are explained through geodesics in GR, but for my model, **without time as fourth dimension**, we can demonstate that in space-space manifold, the object moving perpendicular to the space compression gradient is efectively "perceiving less space density" along his motion direction, which compensates for the space compression gradient and results in the expected orbital motion.
  - The perihelion precession and the Lense–Thirring frame dragging effect of Kerr metric in rotating black hole with non-zero time-to-space transformation components is yet to be properly understood within this context and reduced manifold without time should still preserve a reduced **diffeomorphism invariance**. I believe that Mach's principle is relevant here and the vectorial inertial coupling is the key in my model. The massive components of a rotating object simply experience centripetal acceleration, which generates a "vortex" in the inertial coupling, yielding into the frame dragging effect. This problem is essentially similar to the spining skater relative to the rest of the universe.

- I will show that GR's model of curved spacetime emerges from arrangement of the causal links (discrete inertial information propagating along null trajectories). Particle density (mass) gradient translates into the causal links stretching in the direction of the gradient, yielding into the curvature description.
- Acceleration between two particles makes a wavefront in their causal link, which is the mechanism of the gravitational wave. If the causal link goes through an event horizon, the wavefront is steeper than the speed of causality, and the link tears down.
- The giant laser interferometers (LIGO, VIRGO) work because the proper distance between the mirrors is changing as the wave propagetes (https://arxiv.org/pdf/gr-qc/0702079,https://physics.stackexchange.com/questions/699759/searching-for-an-intuitive-explanation-about-how-gravitational-waves-can-be-de), since the mirrors are accelerated by tidal forces due to the propagating space compression gradient, not by the static space density (because that applies to the proper distances as well as to the light speed, cancelling the measurable effect out). Gravitational waves should be demonstrated in the simulation hereby as the result of inertial coupling.

### Super wild and nice to get: QUANTUM MECHANICS (speculative)

- Electrostatic force is a fundamental property of the particle (fermion) and its charge (Gauss's law) and the action quanta (boson) are distributed across causal links (my claim).
- The particle is not a point, but a potentiality for interaction. Causal link is as fundamental as the particle itself, or more. Space is a container for fermionic particles (endings of the causal links), and the links live in the quantum substrate.
- Causal links replace bosons - mediators of the interaction. They themselves are not causaly linked to anything. This reflects the facts that in conventional theory, bosons always travel at the speed of light along null trajectories and they are not observed as particles.
- Does the discreteness of causal links cause the quantum effects we observe in spacetime? Does the transmitting, actualized particle "choose" which causal link to deliver the quanta to?
- Wave-particle duality? Can we recreate e.g. the double slit experiment with causal links? We would have to demonstrate the experiment for both bosons and fermions. Since bosons are just waves in the causal link propagation, the diffraction would probably spontaneously arise around endges comparable to the wavelength, because of one side of the causal link is blocked, yielding to diffraction / interference from multiple slits. However, how about fermions? We can't accelerate a fermion to c but the de Broglie frequency is nonzero only when a particle is moving and this may be result from advanced / retarded wavefront of a moving particle. Fermion is an ontological primitive in our model, but it's way to manifest itself into existence is only through bosons, and bosons propagate along the causal links. This mechanism could manifest into wave-like behavior of massive particles that are conventionaly demonstrated in wave-particle duality in conventional quantum menchanics.
- Collapse of the wave function is the actualization step in the aggregates from all incoming causal actions, which is evaluated only when the particle has to deliver the causal action to the adjacent links to other particles.
- By applying a variant of gaguge theory to the causal links (close to the end), can we obtain the strong and weak nuclear forces?
- Transactional interpretation of quantum mechanics? Is my proposal version of the John Wheeler's absorber theory? This theory involves a backward popagation. Recently they added mechanism of handshake between particles through offer waves, etc. Result of the handshake is the decission on where the quantum will be delivered. Can we implement this in the simulation? Currently, we deliver the action everywhere homogenously.
- I see virtual immediate action at the beginning of the causal link and symmetricity of propagation. Can the causal link be the mechanism of quantum entanglement?
- **Speculation and echoing the 'digital physics'**: Causal links participate in causal sets. Universe "computationally optimizes" itself, so links in irrelevant causal sets are not evaluated. If a causal set is absolutely isolated, the superposition doesn't collapse and the potentiality doesn't translate into observable fermionic particles. Physicists came with wave functions and Schrodinger equation to describe the potentiality, but it doesn't represent a physical entity. I speculate that when the universe's substrate is forced to evaluate a causal link from one enclosed set to another, this is what we call observation and when the entire set's wave function collapses. The question of what is the ultimate triggerer of the collapse remains open. Accepting that all causal links are evaluated constantly would require computational complexity of the universe O(x^2).

## Acknowledgements

- **Channels and podcasts:** Sabine Hossenfelder, Independent Physics, Dialect, Chris The Brain, Theories of Everything, Vsauce, Veritasium, 3Blue1Brown, Kurzgesagt, Closer to Truth, PBS Space Time
- **Physicists and philosophers:** Alfred North Whitehead, Ernst Mach, John Wheeler, Roger Penrose, Stephen Wolfram, Ruth Kastner, Felix Finster, Jacob Barandes, Jonathan Fay, Dennis Braun

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

Jaromir Dvorak, jery9871@gmail.com

---

## What the sim is able to demonstrate now (milestones)

- [x] ELECTROMAGNETISM and SPECIAL RELATIVITY
- [ ] INERTIA, GRAVITY and ROTATING REFERENCE FRAME
- [ ] GENERAL RELATIVITY
- [ ] QUANTUM MECHANICS

---

#### Inertia & Gravity merger 2 (probably will not be used)

Schrodinger's Langrangian to implement Mach's principle is said to be rotationally and translationally invariant, but the 'problem' is that it produces anisotropic inertia. Is it really a problem for us? Treder (1972) wrote a variant with scalar inertia, but not rotationally invariant:

$$L_{ij} = \delta \frac{m_i m_j}{c^2 r_{ij}} \mathbf{v}_{ij}^2 - \frac{m_i m_j}{r_{ij}},$$

Denis Braun adopted Teder's model: "Such Lagrange function was first proposed by Hans-Jürgen Treder in his ‘Inertia-free mechanics’":

$$L = T - V = \sum_{i>j} \frac{Gm_i m_j}{r_{ij}}\left(1 + \mu\frac{v_{ij}^2}{c^2}\right).$$

Motion equations from Denis Braun's website (note that the quantities seem absolute again, but let's presume they are referred to each particle's reference frame):

$$\frac{2\varphi_i m_i}{c^2} \frac{\partial \mathbf{v}_i}{\partial t} = \nabla_i \varphi_i + \frac{2}{c} \frac{\partial \mathbf{A}_i}{\partial t},$$

Where phi_i and A_i are scalar and vectorial potentials:

$$\varphi_i = \sum_{j \neq i} \frac{m_j}{r_{ij}}, \qquad \mathbf{A}_i = \sum_{j \neq i} \frac{m_j \boldsymbol{\beta}_j}{r_{ij}}.$$

#### Now, how make simulation from this?

First, modify the first equation to work with Beta (dimensionless speed in v/c):

$$\frac{2\varphi_i m_i}{c} \frac{\partial \boldsymbol{\beta}_i}{\partial t} = \nabla_i \varphi_i + \frac{2}{c} \frac{\partial \mathbf{A}_i}{\partial t}$$

Rearrange so that only the speed differentiation stays on the left side and replace partial time derivative with dot notion:

$$\dot{\boldsymbol{\beta}}_i = \frac{1}{\varphi_i m_i}\left(\frac{c}{2} \nabla_i \varphi_i + \frac{\partial \mathbf{A}_i}{\partial t}\right)$$

Assuming r_ij and m_j do not contribute to the differentiation (constants), differentiate the velocities in the vector potential and evaluate nabla operator to get scalar potential:

$$\nabla_i \varphi_i = -\sum_{j \neq i} \frac{m_j \mathbf{r}_{ij}}{r_{ij}^3}, \qquad \frac{\partial \mathbf{A}_i}{\partial t} =  \sum_{j \neq i} \frac{m_j \dot{\boldsymbol{\beta}}_j}{r_{ij}}$$

Substitute and simplify:

$$\dot{\boldsymbol{\beta}}_i = \frac{1}{\varphi_i m_i}\sum_{j \neq i} m_j \left(\frac{\dot{\boldsymbol{\beta}}_j}{r_{ij}} -  \frac{c \mathbf{r}_{ij}}{2 r_{ij}^3}  \right)$$

---
