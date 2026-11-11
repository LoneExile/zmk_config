# zmk-config

This is my personal [ZMK](https://zmkfirmware.dev/) configuration.

---

## Keyboards

| Keyboard | Config | Workflow | ZMK |
|----------|--------|----------|-----|
| Urchin | `config/` (`build.yaml`) | `.github/workflows/build.yml` | `main` |
| beekeeb Toucan2 (36-key) | `toucan/` (`toucan/build.yaml`) | `.github/workflows/build-toucan.yml` | `v0.3` |

Toucan2 builds from its own west manifest because its trackpad driver and
144x168 display shield (from
[beekeeb/zmk-keyboard-toucan2](https://github.com/beekeeb/zmk-keyboard-toucan2))
target ZMK v0.3. Its shield is also named `nice_view_gem`, which would clash with the
one urchin uses. `toucan/toucan.keymap` is the urchin layout re-indexed to
Toucan's 42-position matrix.

---

> ZMK Firmware is an open source (MIT) keyboard firmware built on the
> [Zephyr™ Project](https://zephyrproject.org/) Real Time Operating System
> (RTOS). ZMK's goal is to provide a modern, wireless, and powerful firmware
> free of licensing issues.
