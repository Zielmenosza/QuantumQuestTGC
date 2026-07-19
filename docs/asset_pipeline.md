# QuantumQuestTGC Asset Pipeline

QuantumQuestTGC should treat assets as data-driven game content, not one-off drawable references. This keeps Hermes, Maya, Android, and future AR work aligned.

## Goals

- Keep every card, character, room, prop, and AR model addressable by stable IDs.
- Let Hermes generate asset briefs and Maya blockout scripts from game data.
- Keep Android runtime assets under predictable `app/src/main/assets/` folders.
- Preserve provenance from concept → Maya source → exported runtime model.

## Runtime folders

```text
app/src/main/assets/data/cards.json
app/src/main/assets/data/characters.json
app/src/main/assets/data/rooms.json
app/src/main/assets/models/quantumquest/manifest.json
app/src/main/assets/models/quantumquest/characters/
app/src/main/assets/models/quantumquest/cards/
app/src/main/assets/models/quantumquest/rooms/
app/src/main/assets/models/quantumquest/props/
app/src/main/assets/textures/quantumquest/
```

## Preferred formats

- Prefer `glb`/`gltf` for production 3D assets.
- Use `obj` only for simple placeholder models or ARCore sample compatibility.
- Use PNG/WebP textures sized for mobile.
- Keep one small preview image per important card/asset where possible.

## Asset manifest fields

Each model manifest entry should include:

| Field | Purpose |
|---|---|
| `assetId` | Stable ID used by cards/characters/rooms |
| `displayName` | Human-readable name |
| `type` | `character`, `card_prop`, `room`, `prop`, `effect` |
| `runtimeModel` | Path under `app/src/main/assets/` |
| `sourceBrief` | Hermes/Maya brief path |
| `sourceMayaFile` | Maya source scene path, once created |
| `textureSet` | Texture IDs/paths |
| `scale` | Default Android/AR model scale |
| `anchorMode` | `card`, `plane`, `face`, `screen`, or `none` |
| `status` | `briefed`, `blockout`, `runtime_placeholder`, `production` |

## Hermes + Maya workflow

1. Add/update data in `cards.json`, `characters.json`, or `rooms.json`.
2. Ask Hermes to generate or update an asset brief in `docs/asset_briefs/`.
3. Use `D:/Project/HermesMayaGameLab` to create a Maya script/spec for the asset.
4. Export a placeholder model to `app/src/main/assets/models/quantumquest/...`.
5. Add/validate the manifest entry.
6. Load it in Android model viewer or AR placement flow.

## First vertical-slice assets

- `inferno_crystal`
- `tidal_amulet`
- `quest_portal_gate`
- `thorne_quantum_knight`
- `luna_pixel_sorceress`
- `room_fire_arena`
- `room_water_mirage`

## Validation rules

- IDs use lowercase snake case.
- Every model manifest `runtimeModel` either exists or has `status: "briefed"` with an empty model path.
- Card/character data must not hardcode Android resource IDs; map to assets via string IDs.
- AR-specific scale and anchor decisions live in the model manifest, not in card rules.
