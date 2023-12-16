braille = {
  " ": "000000",
  "a": "100000",
  "b": "110000",
  "c": "100100",
  "d": "100110",
  "e": "100010",
  "f": "110100",
  "g": "110110",
  "h": "110010",
  "i": "010100",
  "j": "010110",
  "k": "101000",
  "l": "111000",
  "m": "101100",
  "n": "101110",
  "o": "101010",
  "p": "111100",
  "q": "111110",
  "r": "111010",
  "s": "011100",
  "t": "011110",
  "u": "101001",
  "v": "111001",
  "w": "010111",
  "x": "101101",
  "y": "101111",
  "z": "101011",
}

def solution(plaintext):
  translated = ""
  for i in plaintext:
    if (ord(i) >= 97 or i == " "):
      translated += braille[i.lower()]
    else:
      translated += "000001"
      translated += braille[i.lower()]
  return translated

print(solution("The quick brown fox jumps over the lazy dog"))
print(solution("code"))
print(solution("Braille"))
