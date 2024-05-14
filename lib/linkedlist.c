#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//-------------------------//
//      unsigned int       //
//-------------------------//

typedef struct uint8Node uint8Node;
typedef struct uint16Node uint16Node;
typedef struct uint32Node uint32Node;
typedef struct uint64Node uint64Node;

typedef struct uint8Node
{
  uint8_t value;
  uint8Node *nextNode;
} uint8Node;

typedef struct uint16Node
{
  uint16_t value;
  uint16Node *nextNode;
} uint16Node;

typedef struct uint32Node
{
  uint32_t value;
  uint32Node *nextNode;
} uint32Node;

typedef struct uint64Node
{
  uint64_t value;
  uint64Node *nextNode;
} uint64Node;

//-------------------------//
//       signed int        //
//-------------------------//

typedef struct int8Node int8Node;
typedef struct int16Node int16Node;
typedef struct int32Node int32Node;
typedef struct int64Node int64Node;

typedef struct int8Node
{
  int8_t value;
  int8Node *nextNode;
} int8Node;

typedef struct int16Node
{
  int16_t value;
  int16Node *nextNode;
} int16Node;

typedef struct int32Node
{
  int32_t value;
  int32Node *nextNode;
} int32Node;

typedef struct int64Node
{
  int64_t value;
  int64Node *nextNode;
} int64Node;

//-------------------------//
//       non-integer       //
//-------------------------//

typedef struct floatNode floatNode;
typedef struct doubleNode doubleNode;

typedef struct floatNode
{
  float value;
  floatNode *nextNode;
} floatNode;

typedef struct doubleNode
{
  double value;
  doubleNode *nextNode;
} doubleNode;

//-------------------------//
//     uint8 functions     //
//-------------------------//

uint8Node *uint8CreateRoot(uint8_t value)
{
  uint8Node *pRoot = malloc(sizeof(uint8Node));
  pRoot->nextNode = 0;
  pRoot->value = value;

  return pRoot;
}

int uint8AddNodeAtIndex(uint8Node *pRoot, uint8_t value, uint64_t index)
{
  if (index < 0)
    return 1;

  uint8Node *newNode = malloc(sizeof(uint8Node));
  memset(newNode, 0, sizeof(*newNode));
  newNode->value = value;

  if (index == 0)
  {
    newNode->value = pRoot->value;
    pRoot->value = value;
    if (pRoot->nextNode != 0)
      newNode->nextNode = pRoot->nextNode;

    pRoot->nextNode = newNode;
    return 0;
  }

  for (uint64_t i = 0; i < index - 1; i++)
  {
    if (pRoot->nextNode == 0)
    {
      pRoot->nextNode = newNode;
      return 0;
    }
    pRoot = pRoot->nextNode;
  }
  if (pRoot->nextNode != 0)
    newNode->nextNode = pRoot->nextNode;

  pRoot->nextNode = newNode;
}

uint8Node *uint8GetNode(uint8Node *pRoot, uint64_t index)
{
  if (index < 0)
    return 0;

  for (uint64_t i = 0; i < index; i++)
  {
    if (pRoot->nextNode == 0)
      return 0;

    pRoot = pRoot->nextNode;
  }
  return pRoot;
}

int uint8DeleteNodeAtIndex(uint8Node *pRoot, uint64_t index)
{
  if (pRoot->nextNode == 0)
    return 1;

  if (index == 0)
  {
    pRoot->value = pRoot->nextNode->value;

    if (pRoot->nextNode->nextNode != 0)
      pRoot->nextNode = pRoot->nextNode->nextNode;
    else
      pRoot->nextNode = 0;

    return 0;
  }
  else if (index != 1)
  {
    for (uint64_t i = 0; i < index - 2; i++)
    {
      pRoot = pRoot->nextNode;
    }
  }

  if (pRoot->nextNode == 0)
    return 1;

  uint8Node *toDeleteNode = pRoot->nextNode;

  if (pRoot->nextNode->nextNode != 0)
    pRoot->nextNode = pRoot->nextNode->nextNode;
  else
    pRoot->nextNode = 0;

  free(toDeleteNode);

  return 0;
}

int uint8DeleteLinkedList(uint8Node **pRoot)
{
  uint8Node *toDeleteNode = 0;
  while ((*pRoot)->nextNode != 0)
  {
    toDeleteNode = *pRoot;
    *pRoot = (*pRoot)->nextNode;
    free(toDeleteNode);
  }
  free(*pRoot);
  *pRoot = 0;
}