# Log Analyzer

A command-line and GUI-based log analysis tool written in C that detects brute-force login attempts by monitoring failed authentication events across log files.

---

## Features

- **Brute-force detection** — Flags any IP address that exceeds 5 consecutive failed login attempts
- **CLI mode** — Run analysis directly from the terminal with a log file argument
- **GUI mode** — GTK3-based graphical interface for point-and-click log analysis
- **Hash map engine** — O(1) average-case IP lookup and fail count tracking
- **Memory safe** — Full cleanup of allocated nodes after every analysis pass

---

## Project Structure

```
log_analyzer/
├── Makefile
├── src/
│   ├── main.c          # CLI entry point
│   ├── gui_main.c      # GUI entry point
│   ├── analyzer.c      # Core analysis logic
│   ├── cli.c           # CLI argument handling
│   ├── gui.c           # GTK3 GUI implementation
│   ├── hashmap.c       # Hash table for IP tracking
│   └── parser.c        # Log line parser
├── include/
│   ├── analyzer.h
│   ├── cli.h
│   ├── gui.h
│   ├── hashmap.h
│   └── parser.h
└── data/
    └── sample.log
```

---

## Requirements

- GCC (via MSYS2 UCRT64 on Windows, or any Unix toolchain)
- GNU Make
- GTK3 (only required for GUI mode)

### Installing dependencies (MSYS2 UCRT64)

```bash
pacman -S make mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-gtk3   # GUI only
```

---

## Building

### CLI version

```bash
make
```

### GUI version

```bash
make gui
```

### Clean build artifacts

```bash
make clean
```

---

## Usage

### CLI

```bash
./log_analyzer data/sample.log
./log_analyzer data/sample.log --detect
```

### GUI

```bash
./log_analyzer_gui
```

Click **Analyze Logs** to run analysis on `data/sample.log`. Alerts are displayed directly in the window.

---

## Log File Format

Each line must follow this exact format:

```
TIMESTAMP USER IP EVENT
```

Example:

```
2026-05-07 admin 192.168.1.1 FAIL
2026-05-07 admin 192.168.1.1 FAIL
2026-05-07 john  10.0.0.5    SUCCESS
```

Valid events are `FAIL` and `SUCCESS`. Any other value is ignored.

---

## Detection Output

When an IP address accumulates 5 or more `FAIL` events, the following alert is produced:

```
[ALERT] Brute-force suspected from IP: 192.168.1.1
```

---

## Planned Features

- `--stats` flag for per-IP and per-user statistics
- Suspicious user detection
- Traffic spike detection
- Configurable detection threshold via CLI flag

---

## Author

Tanvi — Acer Aspire 7
