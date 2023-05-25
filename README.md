# Tpsit ProjectWork, file manager
<p>Il nostro progetto consiste nel ricreare una utility di ricerca e di riorganizzazione dei file tramite l'utilizzo della programmazione concorrente.
Abbiamo sviluppato il nostro lavoro tramite il framework QT, che ci ha permesso di dare un'aspetto al progetto tramite una GUI per il linguaggio C++.</p> 
<h2>Ambiente di sviluppo</h2>
<p>L'ambiente di sviluppo del nostro progetto è un ambiente unix, nel nostro caso in particolare basato su Arch LInux, grazie al quale abbiamo potuto usufruire degli standard POSIX.<br>
  

<ol>
  <li> Le funzioni principali del nostro progetto sono:</li>
  
  - Selezionare su quale cartella è possibile eseguire il progetto;
  - Ricerca di un determinato/a file/cartella tramite il nome;
  - Ricerca, all'interno di tutti i file .txt, di una determinata parola;
  - Creazione di cartelle ordinate che contengo a loro volta file ordinati alfabeticamente;
  - Creazione di cartelle che contengano file dello stesso tipo;
  - Creazione di cartelle che dividano i file in base alla dimensione dello stesso;
  - Ordinamento in ordine alfabetico e rinomina dei file tramite l'utilizzo di un codice numerico;
  - Ordinamento in base alla creazione, dal meno recente al più recente, dei file tramite l'utilizzo di un codice     numerico;
  - Creazione di cartelle che dividono i file in base al proprietario;
  
  sudo apt install g++
```
  
  <li> Accettare l'invito alla repository dalle email </li>
  <li> Accedere su github.com con le credenziali e generare un token</li>
  Per generare il token potete seguire <a href="">questo</a> tutorial
  
  ### COPIATE SUBITO IL TOKEN E SALVATELO IN UN FILE PERCHÉ SI VEDE SOLO UNA VOLTA
  
  <li>In una cartella a vostra discrezione, aprite il terminale e digitate il seguente comando:</li>
  Dove <b> username</b> é il vostro username di github e <b>password</b> é il token appena creato

```console
  
  git clone https://username:password@github.com/leonardocasarotto/PwTpsit
  
```
 </ol>
 Ora avete configurato correttamente tutto.
 
 Quando fate modifiche e volete caricarle usate: 
 
```console
  
  git add *
  git commit -m "messaggio a caso"
  git push
  
```
 Quando volete scaricare modifiche effettuate da qualcun'altro:
 ```console
  

  git pull
  
```
