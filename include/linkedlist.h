#include <stdint.h>

// unsigned int
typedef struct uint8LinkedList
{
  uint8_t value;
  uint8_t *nextNode;
} uint8LinkedList;

typedef struct uint16LinkedList
{
  uint16_t value;
  uint16_t *nextNode;
} uint16LinkedList;

typedef struct uint32LinkedList
{
  uint32_t value;
  uint32_t *nextNode;
} uint32LinkedList;

typedef struct uint64LinkedList
{
  uint64_t value;
  uint64_t *nextNode;
} uint64LinkedList;

// signed int

typedef struct int8LinkedList
{
  int8_t value;
  int8_t *nextNode;
} int8LinkedList;

typedef struct int16LinkedList
{
  int16_t value;
  int16_t *nextNode;
} int16LinkedList;

typedef struct int32LinkedList
{
  int32_t value;
  int32_t *nextNode;
} int32LinkedList;

typedef struct int64LinkedList
{
  int64_t value;
  int64_t *nextNode;
} int64LinkedList;