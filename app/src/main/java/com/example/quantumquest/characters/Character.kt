package com.example.quantumquest.characters

open class Character(
   val id: Int,
   val name: String,
   val health: Int,
   val attack: Int,
   val description: String
) {
   fun displayCharacterInfo() {
      println("Character Name: $name, Health: $health, Attack: $attack, Description: $description")
   }
}