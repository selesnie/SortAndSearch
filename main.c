#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    const char* const key;
    const char* const value;
};

static struct Pair thingsMap[] = {
  {"mercedes-benz", "car"},
  {"polar bear", "animal"},
  {"eiffel tower", "building"},
  {"banana", "fruit"},

  {"bmw", "car"},
  {"dog", "animal"},
  {"louvre", "building"},
  {"carrot", "vegetable"},

  {"audi", "car"},
  {"cat", "animal"},
  {"taj mahal", "building"},
  {"orange", "fruit"}
};

const int MAP_ELEMENT_SIZE = sizeof(thingsMap[0]);

const int MAP_ELEMENTS_COUNT = sizeof(thingsMap) / sizeof(thingsMap[0]);

const char* const KEY_TO_FIND = "louvre";

static int compareMapElements(const void* const lhs, const void* const rhs)
{
    const struct Pair* const a = lhs;
    const struct Pair* const b = rhs;

    if (*a->key < *b->key) return -1;

    if (*a->key > *b->key) return 1;

    return 0;
}

static void printMapElements()
{
    int idx = 0;

    for (; idx < MAP_ELEMENTS_COUNT; ++idx)
    {
        printf("Key: %s, Value: %s\n",
               thingsMap[idx].key,
               thingsMap[idx].value);
    }
}

int main()
{
    printf("Unsorted map\n");
    printMapElements();

    qsort(thingsMap,
          MAP_ELEMENTS_COUNT,
          MAP_ELEMENT_SIZE,
          compareMapElements);

    printf("\nSorted map\n");
    printMapElements();

    const struct Pair mapKey = {.key = KEY_TO_FIND};

    printf("\nSearching %s in the map...\n", mapKey.key);

    const struct Pair* const mapElement = bsearch(&mapKey,
                                                  thingsMap,
                                                  MAP_ELEMENTS_COUNT,
                                                  MAP_ELEMENT_SIZE,
                                                  compareMapElements);

    if (mapElement)
    {
        printf("%s found!\n", mapElement->key);
    }

    return 0;
}
