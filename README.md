# serein-plugin

The native Qt/QML plugin behind the [Serein shell](https://github.com/esrahmn/serein-shell): the `Serein.*` QML
modules for configuration, services (audio, network, sensors, MPRIS, Hyprland, ...), blobs and shaders, image
loading, models, internationalisation and a few utilities.

It is a fork of the plugin that ships with [Caelestia's shell](https://github.com/caelestia-dots/shell)
(GPL-3.0-only), branched from release **v2.5.0**, and is **not affiliated with** the Caelestia project. All credit
for the original code goes to its authors; see [Credits and license](#credits-and-license).

## What is different from the Caelestia plugin

- Everything is renamed: QML modules `Caelestia.*` became `Serein.*` (`import Serein.Config`, ...), the C++
  namespace `caelestia` became `serein`, libraries are `libserein-*plugin.so`, and logging categories start with
  `serein.`.
- **Data paths follow Serein:** the config is read from `~/.config/serein/shell.json`, and the plugin keeps its
  state and caches under `~/.local/state/serein`, `~/.local/share/serein` and `~/.cache/serein`.
- Commands the plugin runs (wallpaper, opening Nexus) call `serein` ([serein-cli](https://github.com/esrahmn/serein-cli))
  instead of `caelestia`.
- The shell's QML (and the Nix and CI files) are not part of this repository; the shell lives in
  [serein-shell](https://github.com/esrahmn/serein-shell). Only the plugin and the small `version` helper are built.

Branch `serein` is the maintained branch (it starts at upstream `v2.5.0`); upstream's `main` has moved on and is
not merged.

## Build and install

Requirements: a C++20 compiler, CMake, Ninja, Qt 6.9+ (base, declarative, shadertools, multimedia, ...),
`libqalculate`, `libpipewire`, `aubio` and `libcava` (headers), plus `qt6-m3shapes` at runtime.

```sh
git clone https://github.com/esrahmn/serein-plugin ~/src/serein-plugin
cd ~/src/serein-plugin
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DVERSION=0.1.1 -DGIT_REVISION="$(git rev-parse HEAD)"
cmake --build build
cmake --install build --prefix ~/.local     # or --prefix /usr (as root) for a system-wide install
```

Without a git tag, pass `-DVERSION=...` and `-DGIT_REVISION=...` as above. A per-user install puts the modules in
`~/.local/lib/qt6/qml/Serein`, so tell Qt about it:

```lua
-- Hyprland Lua config
hl.env("QML_IMPORT_PATH", HOME .. "/.local/lib/qt6/qml")
```

or `export QML_IMPORT_PATH=$HOME/.local/lib/qt6/qml` before running `qs`. You can try a build without installing
it by pointing `QML_IMPORT_PATH` at `build/qml`.

## Credits and license

serein-plugin is a modified version of the plugin in **caelestia-dots/shell**
(<https://github.com/caelestia-dots/shell>), copyright its authors, and it keeps its license.

It is free software, released under the **GNU General Public License v3.0 only**; see [LICENSE](LICENSE). In line
with the GPL, the changes made on top of the original are summarised above and in the git history.
