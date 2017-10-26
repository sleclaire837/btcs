
#ifndef BTCS_SCRIPT_H
#define BTCS_SCRIPT_H

#include "stack.h"

// Maximum number of bytes pushable to the stack
static const unsigned int MAX_SCRIPT_ELEMENT_SIZE = 520;

// Maximum number of non-push operations per script
static const int MAX_OPS_PER_SCRIPT = 201;

// Maximum number of public keys per multisig
static const int MAX_PUBKEYS_PER_MULTISIG = 20;

// Maximum script length in bytes
static const int MAX_SCRIPT_SIZE = 10000;

// Threshold for nLockTime: below this value it is interpreted as block number,
// otherwise as UNIX timestamp.
static const unsigned int LOCKTIME_THRESHOLD = 500000000; // Tue Nov  5 00:53:20 1985 UTC

struct script {
  struct stack data;
  struct stack pushdata; // a stack of pushdata stacks
};

int  script_new(struct script *);
void script_free(struct script *);
int  script_eval(struct stack *, struct stack*);
void script_print_ops(struct stack *);
void script_print_vals(struct stack *);


#endif /* BTCS_SCRIPT_H */
