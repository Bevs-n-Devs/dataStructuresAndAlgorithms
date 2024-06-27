24/05/2024
# Code Wars: [Pete The Baker](https://www.codewars.com/kata/525c65e51bf619685c000059)

Pete likes to bake some cakes. He has some recipes and ingredients.
Unfortunately he is not good in maths. Can you help him to find out,
how many cakes he could bake considering his recipes?

Write a function `cakes()`, which takes the recipe (object) and the
available ingredients (also an object) and returns the maximum number
of cakes Pete can bake (integer). For simplicity there are no units
for the amounts (e.g. 1 lb of flour or 200 g of sugar are simply 1 or
200). Ingredients that are not present in the objects, can be
considered as 0.

***Break It Down For Me***
*Pete wants to bake cakes using a recipe and the ingredients he has.* 
*Write a function `cakes()` that takes two dictionaries: one for the recipe (ingredients needed) and one for the ingredients he has available.* 
*The function should return the maximum number of cakes Pete can make with the given ingredients.* 
*If an ingredient is missing, Pete can't make any cakes.*

### Examples:
```
// must return 2
cakes({flour: 500, sugar: 200, eggs: 1}, {flour: 1200, sugar: 1200,
eggs: 5, milk: 200});
// must return 0
cakes({apples: 3, flour: 300, sugar: 150, milk: 100, oil: 100},
{sugar: 500, flour: 2000, milk: 2000});
```

# Python
```
print("Code Wars: Pete The Baker Challenge")


def cakes(recipe, ingredients):
    max_cakes = float('inf')
    for ingredient, amount_needed in recipe.items():
        if ingredient in ingredients:
            max_cakes = min(max_cakes, ingredients[ingredient] // amount_needed)
        else:
            return 0
    return max_cakes


recipe = {'flour': 500, 'sugar': 200, 'eggs': 1}
available = {'flour': 1200, 'sugar': 1200, 'eggs': 5, 'milk': 200}
print(cakes(recipe, available))
```