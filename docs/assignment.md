# Coursework brief

This project started as the object-oriented programming assignment (OOP, University of
Bucharest). The original requirements are reproduced below in Romanian, each followed by how
the current code satisfies it. The public README describes the project on its own terms; this
file exists so the coursework checklist stays auditable.

| # | Requirement (original) | Status | Where |
|---|---|---|---|
| 1 | *Definirea a minim 3-4 clase folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici.* | Done | Five classes, all composed: `Interface` holds a `Sample`, `Sample` composes `Matrix` + `Vector`, `CsvParser` returns a `Sample`. No inheritance anywhere. |
| 2 | *Constructori de inițializare cu parametri pentru fiecare clasă.* | Done | `Vector(const float*, int)`, `Matrix(Shape)`, `Sample(Matrix, Vector, names, label)`, `CsvParser(path, delimiter)`, `Interface(path)`. |
| 3 | *Pentru o aceeași (singură) clasă: constructor de copiere, operator= de copiere, destructor.* | Done | The full rule of three on **both** `Vector` (`src/Vector.cpp`) and `Matrix` (`src/Matrix.cpp`), including the self-assignment guard and allocate-before-release ordering. |
| 4 | *operator<< pentru toate clasele pentru afișare (std::ostream) folosind compunere de apeluri cu operator<<.* | Done | All five classes. The chain is genuine: `Interface`'s operator calls `Sample`'s, which calls `Matrix`'s and `Vector`'s. |
| 5 | *Cât mai multe const (unde este cazul) și funcții private.* | Done | Const-qualified accessors and const overloads of `operator[]` throughout; private helpers `Vector::release`, `Matrix::release`/`allocate`, `Sample::correlation`, `CsvParser::splitLine`, and every `Interface` menu action. |
| 6 | *Implementarea a minim 3 funcții membru publice pentru funcționalități netriviale, dintre care 1-2 mai complexe.* | Done | `CsvParser::load` (two-pass validating parser), `Sample::rankFeaturesByCorrelation` (standardise, correlate, sort), `Sample::describe`, `Matrix::standardized`, `Vector::standardized`. |
| 7 | *Scenariu de utilizare cu sens: crearea de obiecte și apelarea funcțiilor membru publice în main; exemple de date de la tastatură în tastatura.txt.* | Partial | `main.cpp` builds an `Interface` and runs either the menu or `--demo`; the menu reaches every public operation, but `main` itself does not call each one directly. Keyboard input examples live in `tastatura.txt`. |
| 8 | *Minim 50-55% din codul propriu să fie C++, .gitattributes configurat corect.* | Done | 100% C++ excluding CMake/YAML; `.gitattributes` pins the language and marks build output as generated. |
| 9 | *Tag de git: de exemplu v0.1.* | Pending | To be tagged on the next release. |
| 10 | *Serviciu de integrare continuă (CI) cu toate bifele.* | Done | `.github/workflows/ci.yml` configures, builds and smoke-tests on Linux and macOS. |
| 11 | *Code review #1, 2 proiecte.* | Pending | Coursework step, tracked outside the repository. |

## Notes on the second milestone

The assignment's later stage asks for inheritance and a class hierarchy. The natural place for it
here is the model layer sketched in the README's roadmap: an abstract `Model` with `fit`/`predict`,
specialised by `LinearRegression` and `KNearestNeighbours`, both consuming a `Sample`. The container
and parsing layers are deliberately finished first so that hierarchy has something correct to stand on.
