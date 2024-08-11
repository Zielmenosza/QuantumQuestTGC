
package com.example.quantumquest

import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class LoginActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)

        val intent = Intent(this, com.example.quantumquest.activities.MainActivity::class.java)
        startActivity(intent)
        finish()
    }
}
