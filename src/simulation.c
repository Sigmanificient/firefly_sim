#include "firefly.h"
#include "firefly_utils.h"

void simulate_firefly_steps(int steps)
{
    firefly_t *firefly = firefly_init();

    if (!firefly)
        return;
    for (int i = 0; i < steps; i++) {
        firefly->current_energy = firefly_increment(
            firefly->current_energy,
            firefly->delta_energy
        );
        firefly_display(firefly->current_energy, true);
        if (firefly->current_energy > F_THRESHOLD)
            firefly->current_energy = 0;
    }
}
