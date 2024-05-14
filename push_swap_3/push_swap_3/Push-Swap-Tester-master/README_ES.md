# 🔢 Push_swap Tester

## Dieser Tester bietet folgende Funktionen:

### 🔹 Fehlerprüfung.

### 🔹 Alle möglichen Fälle von 2 bis 5 Zahlen. Überprüfung, ob die Sortierung in weniger als der geforderten Anzahl von Zügen durchgeführt wurde.

### Unendliche Tests mit 100 und 500 Zahlen, bei denen die Effizienz und die Anzahl der Züge angegeben werden.

### Ein Test für jede mögliche Größe von 1 bis 500.

### 🔹 Tests im Falle von bereits sortierten Argumenten.

### 🔹 Indikator für den Bewegungsdurchschnitt.

### Überprüfung von Speicherlecks.

### Bonusprüfung.

## Verwendung

Die Datei push_swap_test.sh und der checker_Mac müssen sich im selben Verzeichnis wie das Programm push_swap befinden. Sobald wir das Terminal öffnen und uns in diesem Verzeichnis befinden, führen wir den Befehl aus: 

````bash push_swap_test.sh```. 

Wir können auch zwei Argumente hinzufügen, die die Anzahl der Tests von 100 und 500 angeben. Wenn keine Argumente eingegeben werden, wird der Standardwert 200 Tests von jedem sein. 

````bash push_swap_test.sh 250 250```. 

<img width=„540“ alt=„Bildschirmfoto 2022-10-09 um 11 06 42 PM“ src=„https://user-images.githubusercontent.com/66915274/194779534-cf66c958-46a4-4c6f-bf2f-587af4ad8f8e.png“>

Wenn Sie den Bonus ausführen möchten:

````bash push_swap_test.sh -b```.

Wenn Sie den Bonus ausführen und die Testmenge auf size100 und size500 setzen wollen:

````bash push_swap_swap_test.sh -b 100 100````.

Übersetzt mit DeepL.com (kostenlose Version)

<img width=„448“ alt=„Bildschirmfoto 2022-10-10 um 3 12 48 AM“ src=„https://user-images.githubusercontent.com/66915274/194788176-19454b9d-61b7-4921-b440-1073c3d22c50.png“>

### ❗️ Wenn ein Test fehlschlägt und Sie das Argument sehen wollen, das an das Programm gesendet wurde, sehen Sie sich die Datei traces.txt an.

# 👀 Visualisierer 

Nützliches Werkzeug, um Ihren Algorithmus grafisch zu visualisieren. Programm erstellt von ![ailopez-o](https://github.com/ailopez-o).

![VISUALIZER REPOSITORY](https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker)

Wenn Sie das Programm ausführen möchten, geben Sie den folgenden Befehl ein. Die Zahl steht für die Anzahl der Argumente, die push_swap erhalten soll.

````bash push_swap_test.sh -v 500````

<img width=„597“ alt=„Bildschirmfoto 2023-01-13 um 5 23 58 PM“ src=„https://user-images.githubusercontent.com/66915274/212369245-54455057-43d9-42c5-a916-a825ff505813.png“>

Wenn Sie den Viewer mit bestimmten Argumenten ausführen möchten, verwenden Sie den folgenden Befehl, gefolgt von den gewünschten Argumenten in Anführungszeichen.

````bash push_swap_test.sh -v2 „1 4 2 3 5“````

## Steuerelemente 🕹.

|KLAUSEL|AKTION|
|---|---|
|``I`| Schritt-für-Schritt-Anleitung|
|`S`| Alle Anweisungen ausführen
|`P`| Pause |
|``1`| Ausführen 'sa'|
|`2`| exec 'sb'|
|`3`| exec 'ra'|| |`4`| exec 'sb'|| Pause
|`4`| exec 'rb'| |
|`5`| exec 'rra'||
|`6`| exec 'rrb'|| |`6`| exec 'rrb'| |`6`| exec 'rrb'||
|`7`| exec 'pa'|
|`8`| exec 'pb'|
|`ESC ❌`|Close|

# Ich hoffe, Sie finden es nützlich! 😁

# Das könnte Sie interessieren!

### - Um meine Progression in Common Core 42 zu sehen ↙️

Übersetzt mit DeepL.com (kostenlose Version)

[HIER](https://github.com/gemartin99/42cursus)

### - Mein Profil im Intranet von 42 ↙️
[HIER](https://profile.intra.42.fr/users/gemartin)

### Kontakt 📥.

### Kontaktieren Sie mich, wenn es Probleme gibt oder Sie Hilfe brauchen! Es kann zukünftigen Studenten helfen! 😁

◦ E-Mail: gemartin@student.42barcelona.com

◦ Linkedin: https://www.linkedin.com/in/gemartin99/

### Contact Ailopez 📬

### Kontaktieren Sie ihn, wenn es irgendwelche Fehler mit dem Visualizer gibt! Er kann zukünftigen Studenten helfen! 😁

◦ E-Mail: ailopez-@student.42barcelona.com

◦ Linkedin: https://www.linkedin.com/in/aitor-lopez-de-audicana-70125b38/

◦ Github: https://github.com/ailopez-o

◦ Intranet-Profil von 42: https://profile.intra.42.fr/users/ailopez-

Übersetzt mit DeepL.com (kostenlose Version)