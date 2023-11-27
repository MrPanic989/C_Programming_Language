/*In this exercise we will implement the following computations as recusrsive functions:
- sum of the numbers between (lower_value, upper_value)
- product of the numbers between (lower_value, upper_value)

E.g.
recursive_sum(1, 10) => 55
recursive_product(1, 10) => 3628800
*/
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "lib.h"

uint32_t recursive_sum(uint32_t lower_value, uint32_t upper_value);
uint32_t recursive_product(uint32_t lower_value, uint32_t upper_value);
void tests();

int main(void)
{
   uint32_t lower_value = 4u;
   uint32_t upper_value = 4u;

   printf("The total sum of the digits from %u to %u is %u!\n", lower_value, upper_value, recursive_sum(lower_value, upper_value));
   printf("The product of the digits between the two numbers %u and %u is %u!\n", lower_value, upper_value, recursive_product(lower_value, upper_value));

    return 0;
}

void tests()
{
    assert(recursive_sum(0, 0) == 0);
    assert(recursive_sum(0, 1) == 1);
    assert(recursive_sum(3, 4) == 7);
    assert(recursive_sum(4, 4) == 4);
    assert(recursive_sum(4, 3) == 0);

    assert(recursive_product(0, 0) == 0);
    assert(recursive_product(0, 1) == 0);
    assert(recursive_product(3, 4) == 12);
    assert(recursive_product(4, 4) == 4);
    assert(recursive_product(4, 3) == 0);
    assert(recursive_product(1, 5) == 120);
}
