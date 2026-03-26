# C++ ML Sandbox


(ai generated description)

C++ ML Sandbox is a hands-on C++ playground built to strip away the "black box." You can load your own .csv datasets and interactively apply basic ML algorithms all powered by a custom linear algebra engine written from scratch.

----------

# ****main workflow of the app****:
The user provides a sample CSV file to which they can apply various basic ML algorithms interactively for educational purposes.


    todo:
    -fix ostream operators -replace get() - DONE
    -sample data generation
    -testing.
    -[] operator overload for both vector and matrix;
    -continue parsecsv: it essentially takes a csv file as an input (using ifstream) and composes one vector and matrix
    objects with parsed data from said csv file; - DK IF COMPOSE OR INHERITANCE
    -csv to txt? / actually parsing the csv for normalized data
    - [...]

    -start implementing model class which will later be used for the ML algorithms

-----------
## Cerințe

    -definirea a minim 3-4 clase folosind compunere cu clasele definite de voi; 
    moștenirile nu se iau în considerare aici - PARTIAL WIP TEMA 2

    -constructori de inițializare cu parametri pentru fiecare clasă - DA

    -pentru o aceeași (singură) clasă: constructor de copiere,
    operator= de copiere, destructor - DA mai putin operator=

    -operator<< pentru toate clasele pentru afișare (std::ostream)
    folosind compunere de apeluri cu operator<< - DA

    -cât mai multe const (unde este cazul) și funcții private - DA

    -implementarea a minim 3 funcții membru publice pentru funcționalități netriviale specifice temei alese,
    dintre care cel puțin 1-2 funcții mai complexe
        nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector - PARTIAL WIP TEMA 2

    -scenariu de utilizare cu sens a claselor definite:
        crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
        vor fi adăugate în fișierul tastatura.txt DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat - DA

    -minim 50-55% din codul propriu să fie C++, .gitattributes configurat corect - DA

    -tag de git: de exemplu v0.1 - WIP TEMA 2

    -serviciu de integrare continuă (CI) cu toate bifele; exemplu: GitHub Actions - WIP TEMA 2

    -code review #1 2 proiecte
