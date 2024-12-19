// https://neetcode.io/solutions/valid-parentheses

// O(n) solution using a stack (arraydeque)
class Solution {
    fun isValid(s: String): Boolean {
        val stack = ArrayDeque<Char>()
        val map: HashMap<Char, Char> = hashMapOf(')' to '(', ']' to '[', '}' to '{') // K: Closer, V: Opener

        for (i in s.indices) {
            val currentElementInMap: Char? = map[s[i]]

            if (currentElementInMap != null) {
                // We are looking at a closer.
                if (stack.lastOrNull() == currentElementInMap) {
                    // The last item is indeed the relevant opener. 
                    stack.removeLast()
                } else {
                    // The last item is NOT the relevant opener.
                    return false
                }
            } else {
                // We are looking at an opener.
                stack.addLast(s[i])
            }
        }

        return stack.isEmpty()
    }
}
