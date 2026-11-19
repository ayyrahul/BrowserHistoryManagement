# Test cases

Run interactively with `./browser_history` (Windows: ` .\browser_history.exe`). These are manual scenarios and expected outcomes, not claims of automated coverage.

| # | Steps | Expected behavior |
|---:|---|---|
| 1 | Back on empty history | “History is empty.” |
| 2 | Forward on empty history | “History is empty.” |
| 3 | Visit `example.com` | Stores `https://example.com`; count becomes 1 |
| 4 | Visit A, B, C; Back twice; Forward once | Current becomes B; list remains A, B, C |
| 5 | Visit A, B, C; Back; visit D | History is A, B, D; C is freed |
| 6 | Search `example` with a matching URL | Matching entries and positions displayed |
| 7 | Search a nonexistent term | “No matching history entries.” |
| 8 | Search `GITHUB` for `github.com` | Case-insensitive match appears |
| 9 | Delete entry 1 from multiple entries | Head and new head's `prev` remain correct |
| 10 | Delete final entry | Tail updates to prior node |
| 11 | Delete current middle entry | Current selects next entry if present |
| 12 | Delete only entry | Head, tail and current become NULL; count 0 |
| 13 | Clear non-empty history and confirm `y` | All nodes freed and count resets to zero |
| 14 | Visit after clearing | A new one-node list is created correctly |
| 15 | Enter `hello` at menu | Invalid input message; menu continues |
| 16 | Delete entry 0 or a number above count | Range error; list unchanged |
| 17 | Enter URL longer than 255 chars | Rejected safely; no node added |
| 18 | Exit with history present | All nodes freed by final cleanup |
| 19 | Delete head, tail and current in succession | List remains navigable with correct pointers |
| 20 | Visit same URL twice | Two distinct nodes with individual timestamps |

## Build verification

Compile with warnings enabled:
```sh
gcc -std=c11 -Wall -Wextra -Wpedantic -O2 main.c history.c navigation.c search.c ui.c -o browser_history
```
Then exercise cases above. For deeper verification, use AddressSanitizer where supported:
```sh
gcc -std=c11 -Wall -Wextra -Wpedantic -fsanitize=address,undefined -g main.c history.c navigation.c search.c ui.c -o browser_history_asan
```
