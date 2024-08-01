
import android.util.Log
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    // Declare native methods
    external fun getCardNames(cardHandles: LongArray?): Array<String>?
    external fun getCardCosts(cardHandles: LongArray?): IntArray?

    // Example usage
    fun displayCardInfo(cardHandles: LongArray?) {
        val cardNames = getCardNames(cardHandles)
        val cardCosts = getCardCosts(cardHandles)

        if (cardNames != null && cardCosts != null) {
            for (i in cardNames.indices) {
                Log.d("CardInfo", "Name: " + cardNames[i] + ", Cost: " + cardCosts[i])
            }
        } else {
            Log.e("CardInfo", "Failed to retrieve card information.")
        }
    }

    companion object {
        // Load the native library
        init {
            System.loadLibrary("quantumquest")
        }
    }
}