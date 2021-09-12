# caesar cipher
```bash
git clone 
cd caesar-cipher
```
#### compile 32 bit binary 

```bash
make compile-32
```
#### compile 64 bit binary 

```bash
make compile-64
```
- default `64 bit` compile

#### change execute permission

```bash
sudo chmod u+x caesar-cipher
```
#### run

```bash
./caesar-cipher -v
```
*output*

```text
1.0
```

#### help 

```bash
./caesar-cipher -h
```
*output*

```text
optional arguments :
    --help, -h			show help
    --version, -v		show version

required arguments :
    --rotate, -r		number of shift(default 13)
    --string, -s		input string

options :
    --encrypt, -e		encrypt input string
    --decrypt, -d		decrypt input string

Example :
	caesar-cipher -r 13 -s ABC -e
	caesar-cipher -r 13 -s CDE -d
```
#### encode

```bash
./caesar-cipher -r 13 -s "ABC" -e
```
*output*

```text
NOP
```
#### decode 

```bash
./caesar-cipher -r 13 -s "NOP" -d
```
*output*

```text
ABC
```

