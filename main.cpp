#include <iostream>
#include <vector>

// fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21, ....
// fib(n): the nth number in the fibonacci series
// fib(1): 1
// fib(2): 1, 1
// fib(n): fib(n-1) + fib(n-2)

// fibonacci(int n) - returns the n first numbers of the series
void fibonacci(int n, int numbers[])
{
    if (n < 1)
        return;

    numbers[0] = 1;

    if (n > 1)
        numbers[1] = 1;

    // fill the rest of the array with fibonacci numbers
    if (n > 2) {
        for (auto i = 3 - 1; i < n; ++i) {
            numbers[i] = numbers[i-1] + numbers[i-2];
        }
    }
}

int test_fibonacci() {
    // much safer than using c-style arrays - preferred option in modern code
    std::vector<int> expected_numbers {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    int num_test = 5;
    int fib_numbers[num_test];
    fibonacci(num_test, fib_numbers);

    for (auto i = 0; i < num_test; ++i) {
        if (fib_numbers[i] != expected_numbers[i]) {
            for (auto i = 0; i < num_test; ++i)
                std::cerr << fib_numbers[i] << ", ";

            std::cerr << std::endl << "!=" << std::endl;

            for (auto i = 0; i < num_test; ++i)
                std::cerr << expected_numbers[i] << ", ";

            return -1; // terminate testing for loop early on error
        }
    }
    return 0;
}



int main() {
    // ensure the function works
    if (test_fibonacci() != 0) {
        std::cout << "fibonacci is currently not working properly." << std::endl;
        return -1;
    }

    int num{0}; // storage class: automatic, created at run time, on the stack. Scope: inside main

    do
    {
        std::cout << "How many fibonacci numbers do you want? (Enter '0' to end program.)" << std::endl;
        std::cin >> num;

        if (num > 0) {
            // *fibonacci_numbers: storage class: automatic, scope: inside if-statement (block-scoped)
            // new int[num]: storage class: dynamic, on the heap, accessible: until delete, scope: wherever there's a pointer to it
            int *fibonacci_numbers = new int[num];

            fibonacci(num, fibonacci_numbers);
            std::cout << "The first " << num << " fibonacci numbers are: " << std::endl;

            for (auto i = 0; i < num; ++i) {
                std::cout << fibonacci_numbers[i] << " ";
            }

            std::cout << std::endl;
            delete[] fibonacci_numbers;
        }
    } while (num > 0);

    return 0;
}
