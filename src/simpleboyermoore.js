define([], function () {
  var ALPHABET_LEN = 256;
  function ord(c) {
    // Returns ASCII code for c
    return c.charCodeAt(0);
  }

  // Bad character table: last[c] contains the distance from the end of the
  // pattern of the last occurrence of c for each character c in the alphabet.
  // If c does not occur in pat, last[c] = pat.length.
  function bad_character_table(pat) {
    var i,
      m = pat.length;
    shift = new Array(ALPHABET_LEN).fill(m);
    for (i = 0; i < m - 1; i++) {
      shift[ord(pat[i])] = m - i - 1;
    }
    return shift;
  }

  function simpleBoyerMoore(pattern, text) {
    var i,
      j,
      comparisons = [],
      matches = [],
      m = pattern.length,
      shift = bad_character_table(pattern),
      equal = function (pos, j) {
        comparisons.push([pos, j]);
        return text[pos] == pattern[j];
      };

    i = m - 1;
    while (i < text.length) {
      j = m - 1;
      k = i;
      while (j >= 0 && equal(k, j)) {
        k -= 1;
        j -= 1;
      }
      if (j < 0) {
        matches.push(comparisons.length - 1);
        i += m;
      } else {
        i += shift[ord(text[i])];
      }
    }

    return { comparisons: comparisons, matches: matches };
  }

  return simpleBoyerMoore;
});
