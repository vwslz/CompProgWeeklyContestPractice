import java.util.*

fun main() {
    val input = Scanner(System.`in`)
    val t = input.nextInt()
    repeat(t) {
        val s = input.next()
        var greater = false
        var less = false
        var equal = false

        for (x in s) {
            when (x) {
                '=' -> equal = true
                '>' -> greater = true
                '<' -> less = true
            }
        }

        when {
            greater && less -> println("?")
            greater && !less -> println(">")
            less && !greater -> println("<")
            equal && !greater && !less -> println("=")
        }
    }
}
