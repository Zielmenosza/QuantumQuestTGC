# Asset Brief: Quest Portal Gate

## Runtime identity

- Asset ID: `quest_portal_gate`
- Card: Quest Portal Gate
- Type: board prop / AR objective marker
- Element: Arcane
- Rarity: Legendary
- Anchor mode: `plane`

## Gameplay purpose

The Quest Portal Gate opens a route to the active quest objective when charged by three elements. In AR it should become the main tabletop destination marker: visible, readable, and rewarding.

## Visual direction

- Ancient floating stone arch with a luminous quantum portal center.
- Mixes fantasy ruins with neon/arcane pixel energy.
- Should look like it belongs with Aqua Mirage / Pixelated Paradise art.
- Strong silhouette: two pillars, top lintel, circular or oval portal field.

## Maya blockout plan

Create a grouped model named `quest_portal_gate_ROOT` with:

1. `gate_left_pillar`: stacked stone blocks, slightly uneven.
2. `gate_right_pillar`: mirrored stacked blocks, not perfectly symmetrical.
3. `gate_top_lintel`: heavy horizontal capstone.
4. `portal_disc`: flat transparent oval/circle plane inside the arch.
5. `portal_inner_ring`: torus/ring placeholder around disc.
6. `rune_stones_01` to `rune_stones_03`: small floating stones around the gate.
7. `plane_anchor_shadow`: soft oval floor shadow placeholder.

## Materials

| Material | Color | Notes |
|---|---|---|
| `mat_ruin_stone` | warm grey/sand | main gate blocks |
| `mat_rune_gold` | gold | runes/accent blocks |
| `mat_portal_teal` | teal/cyan | portal field, emissive later |
| `mat_portal_violet` | violet | secondary energy ring |
| `mat_shadow_soft` | transparent dark | AR grounding placeholder |

## Scale

- Runtime plane-prop height: roughly 3–4 card widths tall in AR.
- Pivot at center of the floor contact point between pillars.
- Must be readable from a slightly elevated phone camera angle.

## Export notes

- Preferred runtime format: `glb`.
- Placeholder runtime path once exported:
  `app/src/main/assets/models/quantumquest/props/quest_portal_gate.glb`
- Keep portal disc separable so the renderer can animate or swap material later.
- Keep names stable for Hermes/Maya scripted revision.

## Acceptance criteria

- Reads as a gate even without textures.
- Has a stable plane anchor pivot.
- Portal field is a separate named object for later VFX.
- Manifest status can move from `briefed` to `blockout` after Maya generation.
