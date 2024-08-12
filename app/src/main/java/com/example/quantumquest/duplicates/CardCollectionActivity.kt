package com.example.quantumquest.duplicates
import com.example.quantumquest.Card


import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.quantumquest.R  // Ensure this import is present

class CardCollectionActivity : AppCompatActivity 
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_card_collection)  // Ensure this references an existing layout file
    }
}