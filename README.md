# Circuits
Verific ce lege cere inputul din string-ul "legea" prin verificarea
fiecarui caracter si salvez toate valorile in matricea "circuit" pe care
o parcurg apoi pe linii, iar pe coloane tipul de variabila (pe coloana
1 si 2 nodul inceput si cel final, coloana 3 curentul, etc in functie
de lege), in paralel cresc vectorul de frecventa "fr" cu fiecare nod
pe care il citesc, iar daca exista un nod cu o singura aparitie atunci
circuitul este deschis in nodul respectiv. Pentru legea 1 fac suma
curentilor care intra si care ies din nodurile citite, iar daca sumele
sunt egale, se respecta legea 1. Pentru legea 2 fac suma tuturor surselor
pe care o compar cu cea a consumatorilor, dupa aplicarea rezistentei,
iar daca diferenta lor e mai mica decat 10^-8 legea 2 se respecta.
