# Tpsit ProjectWork, file manager
## Come configurare l'ambiente di sviluppo
<p>L'ambiente di sviluppo va configurato su sistema operativo basato su linux (io attualmente uso ubuntu, ma anchen ArchLinux non é male). Se non avete linux, create una macchina virtuale per poterlo utilizzare.<br>
  

<ol>
  <li> Installare Qt  e le dipendenze con i comandi</li>
  
```console
  sudo apt-get install build-essential

  sudo apt-get install qtcreator

  sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
  
  sudo apt install cmake
  
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
