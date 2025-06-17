<div align = "center">

[
    <img src="https://raw.githubusercontent.com/carlos-antunis-physics/carlos-antunis-physics/refs/heads/main/assets/UFAL.png" width="150"></img>
](#---)

# Backend do projeto de matematica discreta

**Autores:** [Carlos](https://github.com/carlos-antunis-physics/), [Filipe](https://github.com/FilipeFortaleza), Flavia, [Giovanna](https://github.com/giovannaspace), [Mirian](https://github.com/miriangomes)

[![C programming language](https://img.shields.io/badge/C-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMjggMTI4Ij48cGF0aCBmaWxsPSIjMDM1OTlDIiBkPSJNMTE3LjUgMzMuNWwuMy0uMmMtLjYtMS4xLTEuNS0yLjEtMi40LTIuNkw2Ny4xIDIuOWMtLjgtLjUtMS45LS43LTMuMS0uNy0xLjIgMC0yLjMuMy0zLjEuN2wtNDggMjcuOWMtMS43IDEtMi45IDMuNS0yLjkgNS40djU1LjdjMCAxLjEuMiAyLjMuOSAzLjRsLS4yLjFjLjUuOCAxLjIgMS41IDEuOSAxLjlsNDguMiAyNy45Yy44LjUgMS45LjcgMy4xLjcgMS4yIDAgMi4zLS4zIDMuMS0uN2w0OC0yNy45YzEuNy0xIDIuOS0zLjUgMi45LTUuNFYzNi4xYy4xLS44IDAtMS43LS40LTIuNnpNNjQgODguNWM5LjEgMCAxNy4xLTUgMjEuMy0xMi40bDEyLjkgNy42Yy02LjggMTEuOC0xOS42IDE5LjgtMzQuMiAxOS44LTIxLjggMC0zOS41LTE3LjctMzkuNS0zOS41UzQyLjIgMjQuNSA2NCAyNC41YzE0LjcgMCAyNy41IDguMSAzNC4zIDIwbC0xMyA3LjVDODEuMSA0NC41IDczLjEgMzkuNSA2NCAzOS41Yy0xMy41IDAtMjQuNSAxMS0yNC41IDI0LjVzMTEgMjQuNSAyNC41IDI0LjV6Ii8+PC9zdmc+&style=flat-square)](#---)
[![Web Assembly](https://img.shields.io/badge/Web%20Assembly-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMjggMTI4Ij48cGF0aCBmaWxsPSIjNjU0ZmYwIiBkPSJNLjIyMy4yMjJ2MTI3LjU1NWgxMjcuNTU1Vi4yMjJINzguNTk0Yy4wMTQuMjI3LjAzNi40NTUuMDM2LjY4NiAwIDguMDgtNi41NSAxNC42MjYtMTQuNjMgMTQuNjI2LTguMDc4IDAtMTQuNjI1LTYuNTQ2LTE0LjYyNS0xNC42MjYgMC0uMjMxLjAyMi0uNDU5LjAzMS0uNjg2em0yOS41OTUgNjguNzQ2aDguNDQ1bDUuNzgyIDMwLjczOGguMTA3bDYuOTY4LTMwLjczOGg3LjkwOGw2LjI2NSAzMS4xMTloLjEwNmw2LjU5Ny0zMS4xMTloOC4yODRsLTEwLjc2NSA0NS4xNTZINjEuMTJsLTYuMjEzLTMwLjczOEg1NC44bC02LjcgMzAuNzM4aC04LjU1N3ptNTkuOTk0IDBoMTMuMzM0bDEzLjI4NCA0NS4xNTZoLTguNzdsLTIuODc5LTEwLjA1MUg4OS41OWwtMi4yMTIgMTAuMDVoLTguNVpNOTQuODk1IDgwLjFsLTMuNjg0IDE2LjU3aDExLjQ3M0w5OC40NDggODAuMVoiLz48L3N2Zz4K&style=flat-square)](#---)

</div>

Backend do [projeto de **Criptografia RSA** como **atividade avaliativa**](https://github.com/carlos-antunis-physics/projeto-matematica-discreta/tree/main) da disciplina de **Matemática Discreta** do **1⁰ período** do curso de **Engenharia da Computação** ministrado no semestre **2024.2** no **IC - UFAL** pelo professor Bruno Almeida Pimentel.

> Para rodar apenas o backend para testes, compile o arquivo `main.c` e informe, par cifrar, a mensagem em `mensagem.txt`, ou o texto cifrado em `cifra.txt`, para decifrar, para facilitar a geração de chaves o arquivo `primes.txt` possui alguns números primos.

##  Licença

Os arquivos aqui dispostos, para a construção da página web, foram desenvolvidas sob a [licença MIT](./LICENSE).

### Bibliotecas e dependências

- [**Emscripten.**](https://emscripten.org/) Um compilador completo da linguagem `C` para WebAssembly. 

- [**GNU Multiple Precision Arithmetic Library (GMP).**](https://gmplib.org/) Uma biblioteca livre para aritmética de precisão arbitrária, distribuída segundo a Licença [**GNU LGPL v3**](https://www.gnu.org/licenses/lgpl-3.0.html). Para a substituição da biblioteca, basta efetuar sua instalação via emscripten antes da compilação.

####    Instalação do GMP via emscripten

Para instalar o GMP via emscripten, é necessário primeiramente possuir tal software em seu dispositivo. Para isso, utilize:

```bash
sudo apt-get install git
git clone "https://github.com/emscripten-core/emsdk.git"
cd emsdk
git pull
./emsdk install latest
source ./emsdk_env.sh
./emsdk activate
```

A seguir instale o GMP via emscripten no **diretório raiz** deste projeto.

```bash
wget https://gmplib.org/download/gmp/gmp-[desired-version].tar.xz
tar -xf gmp-*.tar.xz
rm gmp-*.tar.xz
cd gmp-*
emconfigure ./configure --disable-assembly --host=none --build=none
emmake make
```

após esse processo haverá um diretório `gmp-*/` na pasta atual contendo a biblioteca disponível para emscripten. Por fim, para compilar o código `C` para `Web Assembly` utilize

```bash
emcc src/backendRSA.c -o rsa.js -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=[ccall]
```
