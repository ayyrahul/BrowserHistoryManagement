# Browser History Management System (C11)

A menu-driven console DSA project demonstrating browser-like navigation with one dynamically allocated doubly linked list. It does not open websites or use a real browser.

## Build and run

**Windows (MinGW GCC, from this folder):**
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic main.c history.c navigation.c search.c ui.c -o browser_history.exe
.\browser_history.exe
```
**Linux/macOS:** `make` then `./browser_history` (or use the GCC command above). `make clean` removes the executable.

## Features

- Visit URLs (adds `https://` when no `://` scheme is supplied), preserving each visit as its own entry.
- Back/Forward by moving `current`, without deleting history.
- Visiting after Back removes the obsolete forward branch.
- Chronological display, case-insensitive partial search, numbered deletion, confirmed clear, current page, and navigation statistics.
- Line-based input and allocation-failure handling; URL maximum is 255 characters.

## Architecture

- `history.h`: structure, shared state declarations, constants and prototypes.
- `history.c`: global list state, line/numeric input helpers, allocation, branch cleanup and full cleanup.
- `navigation.c`: visit, Back, Forward and current-page display.
- `search.c`: case-insensitive substring search.
- `ui.c`: history display, numbered deletion and statistics.
- `main.c`: menu loop and final cleanup.

## DSA explanation

A **doubly linked list** stores nodes that each point to both their previous and next neighbors. `head` identifies the first entry, `tail` the last, and `current` the selected page. Back assigns `current = current->prev`; Forward assigns `current = current->next`, so both are O(1). A new visit after going Back frees all nodes after `current` before linking the new node, matching browser branching behavior. Deletion first reconnects the target node's neighbors, updates `head`/`tail` when needed, moves `current` to the next entry if possible (otherwise previous), then frees the target. Dynamic allocation lets the list grow as visits occur. Repeated URLs remain separate nodes because they represent separate visits and timestamps.

Search scans each node and compares URL substrings without regard to letter case. It uses O(n) node visits; naive substring comparison may cost O(n × L), where L captures URL/search-term comparison length.

## Complexity

| Operation | Time |
|---|---:|
| Visit at current tail | O(1) |
| Visit after Back | O(k), where k forward nodes are freed; insertion itself O(1) |
| Back / Forward | O(1) |
| Display history | O(n) |
| Search | O(n × L) naive; often simplified to O(n) in introductory DSA |
| Delete by entry number | O(n) locate + O(1) unlink |
| Clear all | O(n) |
| Space | O(n) for n visits |

## Important behavior and limitations

Timestamps are local system time. URLs are stored as entered apart from trimming surrounding whitespace and optional `https://` prefixing; this is a teaching simulation, not URL validation. Entry numbering is chronological and starts at 1. This implementation intentionally uses a single list rather than separate back/forward stacks.
