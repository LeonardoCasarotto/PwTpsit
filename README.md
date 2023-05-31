<h1> Progetto di ricerca e riorganizzazione dei file</h1>

<h2>Introduzione</h2>
<p>Il nostro progetto consiste nella creazione di un'utilità per la ricerca e la riorganizzazione dei file, utilizzando la programmazione concorrente. Abbiamo sviluppato questa soluzione utilizzando il framework Qt, che ci ha permesso di fornire un'interfaccia grafica (GUI) per il linguaggio C++.</p> 


<h2>Ambiente di Sviluppo</h2>

<p>Innanzitutto abbiamo lavorato su sistema operativo basato su <b>UNIX</b>, in modo da poter utilizzare nel nostro progetto gli standard <b>posix</b>.
<br>In particolare, la distro che abbiamo scelto è <b>EndeavourOs</b>, basata su <b>Arch Linux</b>. Per poter sviluppare il software abbiamo usato il software <b> QtCreator</b>

<h2>Funzionalità Principali</h2>
  
<p>Le funzioni principali del nostro progetto sono:</p>
  
 <ul>
   <li>Selezione della cartella in cui eseguire le operazioni di ricerca e riorganizzazione;</li> 
   <li>Ricerca di file o cartelle specifiche in base al nome;</li> 
   <li>Ricerca di una parola all'interno di tutti i file .txt;</li> 
   <li>Creazione di cartelle ordinate che contengono file ordinati alfabeticamente;</li> 
   <li>Creazione di cartelle che raggruppano file dello stesso tipo;</li> 
   <li>Creazione di cartelle che suddividono i file in base alla loro dimensione;</li> 
   <li>Ordinamento alfabetico e rinomina dei file utilizzando un codice numerico;</li> 
   <li>Ordinamento in base alla data di creazione, dal meno recente al più recente, utilizzando un codice numerico;</li> 
   <li>Creazione di cartelle che suddividono i file in base al proprietario.</li> 
  </ul>


</p>
<h2>Getting Started</h2>
<p> É altamente consigliato eseguire il software su sistema operativo Linux. Per eseguire il software, è possibile scaricare direttamente il file eseguibile dalla sezione <a href="https://github.com/LeonardoCasarotto/PwTpsit/releases">release</a> di questa repository, oppure qualora si disponga di Keith Creator nel proprio computer, è possibile scaricare il <a href="">codice sorgente</a> per compilarlo.
  <br>
  da terminale:
  
```console
  
$ git clone https://github.com/leonardocasarotto/PwTpsit.git
  
```
  
ovviamente, dato che questa repository è attualmente privata, sarà necessario effettuare il login con il proprio username di GitHub ed un <a href="https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token">token</a> con accesso alla repository.

