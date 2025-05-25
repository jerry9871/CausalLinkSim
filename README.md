# CausalLinkSim

This humble particle simulator aspires to demonstrate some physical laws as emergent properties from a few, simple interaction principles.

## How to build and run (Windows)

- Clone the repository
- Install minGW-w64 with MSYS2 and SDL3 packages
- Go to the folder and type `make`
- Run `particle.exe` to start

## Preamble

I am neither physicist, nor mathematician, I am just an engineer. Yet I believe that laws of nature must be reducible to a very simple set of rules - with proper formalism. In my view, the current mainstream physics and mathematics is super complex, deviates from experimental verifiability and generates confusions, misunderstandings and paradoxes. Rather than trying to utilize the high-level theories, I am trying to build a simple model of the universe from scratch. I am not trying to prove or disprove anything, just to see if I can get some of the known physical laws as emergent properties from a minimal set of simple rules.

## Inspirations and principles behind

The simulation is built around my idea of replacing **fields** in physics with **causal links**. I define the causal link is a fundamental, unilateral, non-physical coupling relation along which the interaction propagates. A **particle** is a potentiality, that manifests itself into physical existence. Spacetime is the observable metric emerging from the NxN causal link network. Further principles I follow are:

- Causality is fundamental and "speed" of causality is constant and finite.
- Everything only exists in relation to eveyryhing else. Without relation, there is no existence in spacetime and existence loses meaning.
- Block universe doesn't exist and the future is not determined. Observers can't agree on simultaneity and time manifests itself as evolution of the causal links locally.
- Time is not intertwined with space as a dimension, rather it's just the **fundamental causality metric** of space.
- The common notion of a "field" is non-physical in the same way as hereby defined causal link is non-physical, because physicists defined the field as a potentiality for interaction.
- A "field" of any kind requires its own, usually independent reference frame and a metric in spacetime. Therefore, notion of field is abandoned, since the spacetime is emergent here.

## Expected outcomes (wish list)

In the following sections, I will describe the expected simulation outcomes within different physical contextes. The list is not exhaustive and I am open to any suggestions. Everything is written from hands-on engineer's perspective, so please excuse me if I am using improper terminology, mixing things up or minsunderstanding some of the concepts.

### Must have: ELECTROMAGNETISM and SPECIAL RELATIVITY

- Electrostatic force is a fundamental property of the particle and its charge (Gauss's law) and the action quanta are distributed across causal links (my claim).
- Length contraction is emergent phenomena observed within the massive particles and their causal interactions, due to the advanced/retarded interaction delivery along the causal links.
- A light clock moving at constant speed relative to a stationary observer will appear to tick slower due to advanced/retarded wavefront delivery along the causal links. Within the Twin paradox concept, the total tick count measured by moving clock will be less than the stationary clock at reunion, as predicted by the conventional theory. This is due to the combined effect of advanced/retarded wavefront and the inertial coupling (to be shown). A hint can be found in the Dialect video, where they demonstrated that twin paradox can be explained without the need for isotropy of the speed of light.
- Magnetism is a time-dependent rotation of the electrostatic force vector, when observed as contribution from every nearby moving charged particle (Faraday's law in simple terms).
- The Lorentz invariance and gauge symmetries without fields needs to be demonstrated. The Lorentz transformation is a result of the advanced/retarded wavefront delivery along the causal links.
- Light and other electromagnetic waves are emergent properties of the particles and their causal interactions. The combined effect of vector actions propagating along advanced/retarded causality wavefront yields to the perpendicular electric and magnetic propagating fields along null trajectories.

### Nice to get: INERTIA and ROTATING REFERENCE FRAME

- I adhere to Mach's principle: The inertia of a particle is determined by the distribution of all other particles in the universe. Intertia is the fundamental and defining property of space.
- Inertia is an emergent phenomenon from the particles and their interactions, and it follows similar rules as the electrostatic force. Particles are **inertially coupled** to each other with finite speed of causality.
- The particle has no hidden variable to hold its momentum, because that would require a reference frame. Each causal link has it's own momentum-like equivalent state. State vector is a property the causal link, rather than of the particle itself.
- Inertial coupling is not scalar, but vectorial; otherwise "a spinning skater wouldn't feel the centrifugal force". It wouldn't be possible to explain the Coriolis effect, which is also a result of the inertial coupling.
- The claim of GR that spacetime geometry becomes flat Minkowski spacetime far from massive objects is to be questioned. The stress tensor and cosomological constant may be ill defined (my claim). The further away from the massive objects, the further the stretching of the causal links and the lesser the inertial coupling. The spacetime geometry is not flat by default, but rather anti de Sitter-like.
- Dark matter and dark energy are apparent and the observed discrepancies stems from misunderstandings of how inertia and gravity works and from the questioned presumption of the flat spacetime geometry.

### Super nice to get: GRAVITY and GENERAL RELATIVITY

- GR introduces 4D spacetime manifold defined by mass distribution, as a powerful model to evaluate observer-independent spacetime intervals, describe evolution through worldlines and motion of objects through geodesics. However, since time is the foruth dimension in this manifold, many paradoxes arise, such as the idea of static, block universe where past, present and future are equivalent. The "arrow of time" is not rooted in this model. See for exp. "the Andromeda paradox". I postulate that the time is not a coordinate, it is the causality metric of space. Accepting time as "emergence" and purely local phenomenon, devoiding from the block universe and from the necessity to express observer-independent simultaneity, I can show that replacing 4D spacetime manifold with 3D space-space manifold preserves the GR effects:
  - **Scale of time × Scale of space = 1**, which is true at least for any arbitrary, non-rotating Schwarzchild metric, meaning that space scale is enough to preserve the causality metric of time, and vice versa.
  - Time dilation is the result of compressed space around massive objects, which causes the local particles to move slower from external observer's perspective.
  - Inertia (resistence to change motion) is axiomatically the resistence towards locally perceived space compression in the direction of accleration. The compression gradient around massive objects is perceived as acceleration, as formulated within the Einstein's equivalence principle. These gravitational effets are explained through geodesics in GR, but for our model, **without time as fourth dimension**, we can demonstate that in space-space manifold, the object moving perpendicular to the space density gradient is efectively perceiving less space along his motion direction, which compensates for the space density gradient and results in the orbital motion.
  - The frame dragging effect of Kerr metric in rotating black hole with non-zero time-to-space transformation components is yet to be properly understood within this context and reduced manifold without time needs to preserve **diffeomorphism invariance**. I believe that Mach's principle is relevant here and the vectorial inertial coupling is the key in our model. The problem is essentially similar to the spining skater relative to the rest of the universe.
- I will show that curvature of spacetime emerges from arrangement of the causal links (inertial causality propagating null trajectories). Particle density (mass) gradient translates into the causal links stretching in the direction of the gradient.
- Acceleration between two particles makes a wavefront in their causal link. If the causal link goes through an event horizon, the wavefront is steeper than the speed of causality, and the causal link tears down.
- The giant laser interferometers (LIGO, VIRGO) work because the proper distance between the mirrors is changing as the wave propagetes (https://arxiv.org/pdf/gr-qc/0702079,https://physics.stackexchange.com/questions/699759/searching-for-an-intuitive-explanation-about-how-gravitational-waves-can-be-de), since the mirrors are accelerated by tidal forces due to the propagating space density gradient, not by the static space density (because that applies to the proper distances as well as to the light speed, cancelling the measurable effect out). Gravitational waves should be demonstrated in the simulation hereby as the result of inertial coupling.

### Super wild and nice to get: QUANTUM MECHANICS

- Electrostatic force is a fundamental property of the particle (fermion) and its charge (Gauss's law) and the action quanta (boson) are distributed across causal links (my claim).
- The particle is not a point, but a potentiality for interaction. Causal link is as fundamental as the particle itself, or more. Space is a container for fermionic particles (endings of the causal links), and the links live in the quantum substrate.
- Causal links replace bosons - mediators of the interaction. They themselves are not causaly linked to anything. This reflets the facts that in conventional theory, bosons always travel at the speed of light along null trajectories and they are not observed as particles.
- Does the discreteness of causal links cause the quantum effects we observe in spacetime?
- By applying a variant of gaguge theory to the causal links (close to the end), can we obtain the strong and weak nuclear forces?
- Transactional interpretation of quantum mechanics? Is my proposal version of the John Wheeler's absorber theory? This theory involves a backward popagation. Recently they added mechanism of handshake between particles through offer waves, etc. Result of the handshake is the decission on where the quantum will be delivered. Can we implement this in the simulation? Currently, we deliver the action everywhere homogenously.
- I see virtual immediate action at the beginning of the causal link and symmetricity of propagation. Can the causal link be the mechanism of quantum entanglement?
- **Speculation**: Causal links participate in causal sets. Universe "computationally optimizes" itself, so links in irrelevant causal sets are not evaluated. If a causal set is absolutely isolated, the superposition doesn't collapse and the potentiality doesn't translate into observable fermionic particles. Physicists came with wave functions and Schrodinger equation to describe the potentiality, but it doesn't represent a physical entity. I speculate that when the universe's substrate is forced to evaluate a causal link from one enclosed set to another, this is what we call observation and when the entire set's wave function collapses. The question of what is the ultimate triggerer of the collapse remains open. Accepting that all causal links are evaluated constantly would require computational complexity of the universe O(x^2), which is against my intuition.

## Acknowledgements

- **Channels and podcasts:** Independent Physics, Dialect, Chris The Brain, Theories of Everything, Vsauce, Veritasium, 3Blue1Brown, Kurzgesagt, PBS Space Time
- **Current physicists:** Sabine Hossenfelder, Roger Penrose, Ruth Kastner, Jacob Barandes, Lee Smolin, Carlo Rovelli, Robert Laughlin, Avshalom Elitzur

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

Jaromir Dvorak, jery9871@gmail.com

---

## What the sim is able to demonstrate now (milestones)

- [x] ELECTROMAGNETISM and SPECIAL RELATIVITY
- [ ] INERTIA and ROTATING REFERENCE FRAME
- [ ] GRAVITY and GENERAL RELATIVITY
- [ ] QUANTUM MECHANICS
