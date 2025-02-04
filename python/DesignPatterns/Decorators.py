"""
Decorators can be used to enhance functions without
changing the function's internal logic. Instead the
function can be easily maintained, and if different 
cases are needed the decorator can be added to adjust 
for unique use cases.
"""

def turbocharge(func: callable) -> callable:
    """
    Adds turbocharger to vehicle
    """
    def wrapper() -> None:
        """
        Defines the logic to occur before and/or after the
        passed in function is ran
        """
        print("This car will be turbo charged!")
        func()
        print("Now your acceleration will be doubled!!!")

    # decorators return the wrapper function
    return wrapper

# no decorator before the function definition
def drive_a() -> None:
    """
    Fxn to simulate a car driving
    """
    print("I'm driving")

# adding the decorator enhances the function
@turbocharge
def drive_b() -> None:
    """
    Fxn to simulate a car driving
    """
    print("I'm driving")

# First we run the fxn w/o the decorator
drive_a()
print("="*60)
# Next we run the fxn w/ the decorator
drive_b()