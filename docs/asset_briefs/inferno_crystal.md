# Asset Brief: Inferno Crystal

## Runtime identity

- Asset ID: `inferno_crystal`
- Card: Inferno Crystal
- Type: card prop / AR tabletop pickup
- Element: Fire
- Rarity: Rare
- Anchor mode: `card`

## Gameplay purpose

The Inferno Crystal empowers Fire creatures and turns stored heat into burst damage. In AR/tabletop view it should read as a dangerous charged artifact that can sit above a card or board slot.

## Visual direction

- Stylized faceted crystal with a molten inner core.
- Chunky readable silhouette for mobile screens.
- Warm orange/red center with darker obsidian-like base fragments.
- Retro-fantasy pixel-card vibe, but modeled as simple low-poly geometry first.

## Maya blockout plan

Create a grouped model named `inferno_crystal_ROOT` with:

1. `crystal_core_main`: elongated faceted octahedron/prism form.
2. `crystal_core_inner_glow`: slightly smaller duplicate or emissive center shape.
3. `obsidian_base_01` to `obsidian_base_04`: irregular dark rock chunks around base.
4. `fire_orbit_ring`: thin tilted torus/ring placeholder around crystal.
5. `scale_reference_card`: optional disabled/reference card rectangle for card-anchor scale.

## Materials

| Material | Color | Notes |
|---|---|---|
| `mat_inferno_glass` | orange/red | translucent/glossy later |
| `mat_inner_heat` | yellow/white | emissive later |
| `mat_obsidian` | charcoal | rough base |
| `mat_fire_ring` | saturated orange | VFX placeholder |

## Scale

- Runtime card-prop scale should fit within a single card slot.
- Maya blockout default height: about 2.5 units above card plane.
- Pivot at bottom center of base.

## Export notes

- Preferred runtime format: `glb`.
- Placeholder runtime path once exported:
  `app/src/main/assets/models/quantumquest/cards/inferno_crystal.glb`
- Keep geometry low-poly for Android AR.
- Name objects consistently so Hermes can revise the Maya script later.

## Acceptance criteria

- Silhouette is recognizable from a phone screen.
- Model has a clear bottom pivot for card placement.
- Manifest status can move from `briefed` to `blockout` after Maya generation.
