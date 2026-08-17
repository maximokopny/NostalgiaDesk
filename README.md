# NostaDE — Text-Based Desktop Environment

**NostaDE** is a modular, lightweight, text‑user‑interface desktop environment designed for Linux/Unix systems.  
It runs directly in the TTY or inside any terminal emulator, providing a retro‑inspired pseudo‑graphical workspace without relying on X11 or Wayland.

NostaDE brings back the nostalgic aesthetics of classic UNIX terminals while offering a structured, window‑based environment with panels, menus, modules, and a file manager — all rendered in pure text.

---

## ✨ Features

- Pseudo‑graphical window manager  
- Panel with modules (clock, status indicators, etc.)  
- Application menu  
- Built‑in file manager  
- Mouse support (GPM / terminal escape sequences)  
- Customizable keybindings  
- Theme system (colors, borders, styles)  
- YAML/TOML configuration  
- Modular architecture  
- IPC between internal components  
- Works in:
  - pure TTY  
  - terminal under X11  
  - terminal under Wayland  

---

## 🧱 Architecture Overview

```
NostaDE
├── core/          # main event loop, module manager, state
├── renderer/      # pseudo-graphics, drawing, buffers
├── windowing/     # window system, focus, stacking, rules
├── widgets/       # UI components (buttons, lists, dialogs)
├── input/         # keyboard, mouse, hotkeys
├── ipc/           # internal messaging and module communication
├── config/        # configuration loader and parser
└── modules/       # panel, menu, file manager, launcher, settings
```

---

## 📦 Repository Structure

```
NostaDE/
  src/
    core/
    renderer/
    windowing/
    widgets/
    input/
    ipc/
    config/
    utils/
  modules/
    panel/
    menu/
    filemanager/
    launcher/
    settings/
  themes/
    default/
    retro/
    dark/
  docs/
    architecture/
    modules/
    api/
    config/
  examples/
  scripts/
  tests/
  build/
  README.md
  LICENSE
```

---

## 🚀 Goals

- Provide a fully functional TUI desktop environment  
- Deliver a consistent pseudo‑graphical interface in the terminal  
- Offer a modular and extensible architecture  
- Run on minimal systems, rescue environments, and retro hardware  
- Serve as a foundation for a future graphical layer (NostaWM)

---

## 🔧 Build & Installation

*(Build instructions will be added later as the project evolves.)*

---

## 📜 License

To be decided (MIT / BSD / GPL).

---

## 💡 Project Status

NostaDE is under active development.  
Core systems (windowing, panel, menu, file manager) are being implemented step by step.

Contributions, ideas, and feedback are welcome.
