# Six-member team division and viva preparation

| Member | Ownership | Main DSA concepts | Demonstration |
|---|---|---|---|
| 1 | `history.h`, `history.c`: node structure, shared pointers, allocation, freeing and integration | Doubly linked list, dynamic allocation, invariants | Visit three pages and explain `prev`, `next`, `head`, `tail`, `current` |
| 2 | `navigation.c`: Back, Forward, branch deletion behavior | O(1) pointer movement, forward branch | A → B → C, Back, then visit D; show C disappears |
| 3 | `navigation.c`, `ui.c`: visit flow, chronological history, current-page display | insertion, timestamps, traversal | Visit repeated URL twice and show separate entries |
| 4 | `search.c`, string handling and timestamp formatting support | linear search, case-insensitive comparison | Search `GITHUB` against `https://github.com` |
| 5 | `history.c`, `ui.c`: deletion, clear, cleanup and pointer safety | unlinking, edge cases, memory management | Delete head, tail, then current; clear remaining list |
| 6 | `main.c`, `ui.c`, `TEST_CASES.md`: menu, input validation, stats and demo | input parsing, position calculation, test design | Enter invalid menu text, inspect stats, exit cleanly |

## Individual viva questions (simple answers)

### Member 1 — structure and memory
- **Why use a doubly linked list?** It lets us move backward and forward directly from the current node.
- **Why use `malloc`?** The number of visits is not known in advance, so nodes are created at runtime.
- **What must remain true?** `head->prev` and `tail->next` are NULL; neighbor links agree; `current` is NULL exactly when history is empty.

### Member 2 — navigation
- **Why is Back O(1)?** It follows one pointer, `current->prev`.
- **Does Back delete anything?** No, it only changes `current`.
- **Why remove the forward branch on a new visit?** A new navigation choice replaces the old future path.

### Member 3 — visits and display
- **Why keep duplicate URLs?** Each visit is a distinct event with its own timestamp and position.
- **How is history chronological?** New nodes are linked after the selected current node; display traverses from head to tail.
- **What is `tail` for?** It identifies the last node and makes tail insertion O(1) when current is tail.

### Member 4 — search and timestamps
- **What is linear search?** Checking entries one by one until all possible matches are found.
- **How is search case-insensitive?** Characters are compared after conversion with `tolower`.
- **What does `time(NULL)` return?** The current calendar time as a `time_t` value.

### Member 5 — deletion and cleanup
- **How do we delete a middle node?** Connect its previous node to its next node, then free it.
- **What if current is deleted?** Select its next node if one exists; otherwise select its previous node.
- **Why call `free`?** To return dynamically allocated memory and avoid leaks.

### Member 6 — UI and testing
- **Why use `fgets` instead of `scanf` for text?** It reads a bounded line and allows safer input handling.
- **Why validate menu input?** Text or out-of-range numbers should not crash or confuse the menu.
- **How are pages before/after counted?** Traverse the list and count nodes on either side of `current`.

All members should understand the shared list invariants and be ready to explain how their module integrates with the others.
