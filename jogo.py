import random

def desenha_forca(vidas):
    if vidas == 5:
        print("Vai errar tudo")
    elif vidas == 4:
        print("Começou errando, vai só ladeira abaixo")
    elif vidas == 3:
        print("Vai errar de novo")
    elif vidas == 2:
        print("Quase morrendo em")
    elif vidas == 1:
        print("Vai perder já já")
    elif vidas == 0:
        print("Nem pra isso serve")

palavras = ["c", "python", "html", "css", "javascript", "php", "java", "swift", "go", "c#", "c++", "sql", "ruby"]
dicas = [
    ["d1p1", "d1p2", "d1p3", "d1p4", "d1p5", "d1p6", "d1p7", "d1p8", "d1p9", "d1p10", "d1p11", "d1p12", "d1p13", "d1p14", "d1p15"],
    ["d2p1", "d2p2", "d2p3", "d2p4", "d2p5", "d2p6", "d2p7", "d2p8", "d2p9", "d2p10", "d2p11", "d2p12", "d2p13", "d2p14", "d2p15"],
    ["d3p1", "d3p2", "d3p3", "d3p4", "d3p5", "d3p6", "d3p7", "d3p8", "d3p9", "d3p10", "d3p11", "d3p12", "d3p13", "d3p14", "d3p15"],
    ["d4p1", "d4p2", "d4p3", "d4p4", "d4p5", "d4p6", "d4p7", "d4p8", "d4p9", "d4p10", "d4p11", "d4p12", "d4p13", "d4p14", "d4p15"]
]

vidas = 5
acertos = 0
palavra_escolhida = random.choice(palavras)
palavra_adivinhada = "-" * len(palavra_escolhida)
palavras_adivinhadas = [False] * len(palavra_escolhida)

print("\tJOGOZINHO DA FORCAZINHA\n")

while acertos < len(palavra_escolhida):
    desenha_forca(vidas)
    print(palavra_adivinhada)
    print("Já acertou:", acertos)
    print("Vidas até agora:", vidas)
    letra = input("Tenta aí, digita 'tentar'\n").lower()

    if letra == "sair":
        print("Correu kkk")
        exit()
    elif letra == "tentar":
        palavra_tentativa = input("Digite a palavra: ").strip()
        if palavra_tentativa == palavra_escolhida:
            print("Pelo menos serve pra alguma coisa!")
            exit()
        else:
            print("Burro demais!!")
            vidas = 0
            desenha_forca(vidas)
            exit()

    encontrou_letra = False
    for i, char in enumerate(palavra_escolhida):
        if palavras_adivinhadas[i] or char != letra:
            continue
        palavras_adivinhadas[i] = True
        palavra_adivinhada = palavra_adivinhada[:i] + letra + palavra_adivinhada[i+1:]
        encontrou_letra = True
        acertos += 1

    if not encontrou_letra:
        vidas -= 1

    if vidas == 0:
        print("Burro demais 'ACEFALO'!")
        desenha_forca(vidas)
        exit()

print("Pelo menos serve pra alguma coisa!")
