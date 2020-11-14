#dictionary of names, and phone numbers
import re
#dna_sequences = {"AGATC": 0,"TTTTTTCT": 0, "AATG": 0,"TCTAG": 0,"GATA": 0,"TATC": 0,"GAAA": 0,"TCTG": 0}

dna_sequences = [
    ["AGATC" , 0],
    ["TTTTTTCT" , 0],
    ["AATG" , 0],
    ["TCTAG" , 0],
    ["GATA" , 0],
    ["TATC" , 0],
    ["GAAA" , 0],
    ["TCTG" , 0]
]

print("AGATC = ", dna_sequences[0])

dna_strand = "AAGGTAAGTTTAGAATATAAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAGGAGATCAGATCAGATCAGATCTATCTATCTATCTATCTATCAGAAAAGAGTAAATAGTTAAAGAGTAAGATATTGAATTAATGGAAAATATTGTTGGGGAAAGGAGGGATAGAAGGAGATC"


dna_finder =[ ["AGATC" , re.findall(r'(?:AGATC)+', dna_strand)],
    ["TTTTTTCT", re.findall(r'(?:TTTTTTCT)+', dna_strand)],
    ["AATG" , re.findall(r'(?:AATG)+', dna_strand)],
    ["TCTAG", re.findall(r'(?:TCTAG)+', dna_strand)],
    ["GATA", re.findall(r'(?:GATA)+', dna_strand)],
    ["TATC", re.findall(r'(?:TATC)+', dna_strand)],
    ["GAAA", re.findall(r'(?:GAAA)+', dna_strand)],
    ["TCTG",  re.findall(r'(?:TCTG)+', dna_strand)],
]

#AGATC = max(map(len,re.findall(r'(?:AGATC)+', dna_strand ))// len("AGATC")
#AGATC = re.findall(r'(?:AGATC)+', dna_strand)
if dna_finder[1][1] != 0:
    max_dna = max(map(len,(dna_finder[1][1]))) // len(dna_finder[1][0])
elif dna_finder == 0:
    max_dna = 0
else: 
    max_dna = 0


print(max_dna)
