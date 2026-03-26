# C++ ML Sandbox


(ai generated description)

C++ ML Sandbox is a hands-on C++ playground built to strip away the "black box." You can load your own .csv datasets and interactively apply basic ML algorithms all powered by a custom linear algebra engine written from scratch.

main workflow of the app:
The user provides a sample CSV file to which they can apply various basic ML algorithms interactively for educational purposes.


    todo:
    -fix ostream operators -replace get()
    -[] operator overload for both vector and matrix;
    -continue parsecsv: it essentially takes a csv file as an input (using ifstream) and composes one vector and matrix
    objects with parsed data from said csv file;
    -generate sample data function for easier debugging
    - [...]

    -start implementing model class which will later be used for the ML algorithms

Cerințe

    definirea a minim 3-4 clase folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici
    constructori de inițializare cu parametri pentru fiecare clasă
    pentru o aceeași (singură) clasă: constructor de copiere, operator= de copiere, destructor

    operator<< pentru toate clasele pentru afișare (std::ostream) folosind compunere de apeluri cu operator<<
    cât mai multe const (unde este cazul) și funcții private
    implementarea a minim 3 funcții membru publice pentru funcționalități netriviale specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
        nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
    scenariu de utilizare cu sens a claselor definite:
        crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
        vor fi adăugate în fișierul tastatura.txt DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
    minim 50-55% din codul propriu să fie C++, .gitattributes configurat corect
    tag de git: de exemplu v0.1
    serviciu de integrare continuă (CI) cu toate bifele; exemplu: GitHub Actions
    code review #1 2 proiecte
