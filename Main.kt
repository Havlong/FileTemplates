import java.io.*
import kotlin.system.measureTimeMillis

/**
 * ${DAY}.${MONTH}.${YEAR}
 * ${NAME}
 *
 * @author Havlong
 * @version v1.0
 */
class LineReader(tempReader: Reader) {
    private val reader = BufferedReader(tempReader)
    fun hasNext() = peek() != -1
    private fun peek(): Int {
        reader.mark(1)
        return reader.read().also { reader.reset() }
    }
    fun skipSpaces() {
        while (Character.isWhitespace(peek()))
            reader.read()
    }
    fun readLine() = reader.readLine()
    fun longList() = readLine().split(' ').map(String::toLong)
    fun intList() = readLine().split(' ').map(String::toInt)
}

typealias ML = MutableList<Long>
typealias MI = MutableList<Int>
typealias LL = List<Long>
typealias LLL = List<LL>
typealias PLL = Pair<Long, Long>
typealias PPLL = Pair<Long, PLL>

const val M7 = 1000000007L
const val M9 = 1000000009L
const val MFFT = 998244353L
const val INF = 2000000000000000000L

fun lowerBound(from: Long, to: Long, comparison: (Long) -> Long): Long {
    var left = from
    var right = to + 1
    while (left < right) {
        val mid = (left + right) / 2
        val result = comparison(mid)
        if (result >= 0) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return left
}

fun upperBound(from: Long, to: Long, comparison: (Long) -> Long): Long {
    var left = from
    var right = to + 1
    while (left < right) {
        val mid = (left + right) / 2
        val result = comparison(mid)
        if (result > 0) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return left
}

fun <T : Comparable<T>> List<T>.upperBound(key: T, from: Int = 0, to: Int = size - 1): Int {
    return upperBound(from.toLong(), to.toLong()) { this[it.toInt()].compareTo(key).toLong() }.toInt()
}

fun <T : Comparable<T>> List<T>.lowerBound(key: T, from: Int = 0, to: Int = size - 1): Int {
    return lowerBound(from.toLong(), to.toLong()) { this[it.toInt()].compareTo(key).toLong() }.toInt()
}

fun binPow(number: Long, power: Long, mod: Long): Long {
    var result = 1L
    var a = number % mod
    var n = power
    while (n > 0) {
        if (n % 2 != 0L)
            result = (result * a) % mod
        a = (a * a) % mod
        n /= 2
    }
    return result
}

tailrec fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)

fun lcm(a: Long, b: Long) = a * b / gcd(a, b)

fun main(args: Array<String>) {
    if (args.isNotEmpty() && args[0] == "local") {
        val reader = LineReader(FileReader("input.txt"))
        PrintWriter(File("output.txt")).use {
            while (reader.hasNext()) {
                it.println("\n${measureTimeMillis {
                    solve(reader, it)
                }} ms\n")
                reader.skipSpaces()
            }
        }
    } else {
        val reader = LineReader(InputStreamReader(System.`in`))
        PrintWriter(System.out).use { solve(reader, it) }
    }
}

fun solve(reader: LineReader, writer: PrintWriter) {

}
