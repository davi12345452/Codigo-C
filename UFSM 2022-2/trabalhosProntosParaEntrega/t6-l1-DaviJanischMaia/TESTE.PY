while True:
    valor = float(input("Digite o valor que deseja apostar: "))
    escolha = int(input("Digite que esporte você quer(1-Futebol/2-Basquete): "))
    tamanho = int(input("Digite quantos jogos você quer analisar ao mesmo tempo: "))
    betfair = []
    betano = []
    pixbet = []
    pinnacle = []
    if escolha == 1:
        for i in range(tamnho):
            betfair.append(str(input("Digite o link da Betfair: ")))
            betano.append(str(input("Digite o link da Betano: ")))
            pixbeb.append(str(input("Digite o link da Pixbet: ")))
            pinnacle.append(str(input("Digite o link da Pinnacle: ")))

        while True:
            for i in range(tamanho)
                botFutebol.botFutebol(f'{betfair[i]}{finalLinks[0]}', betano[i], pixbet[i], f'{pinnacle[i]}{finalLinks[1]}', valor, path)

    else:
        for i in range(tamnho):
            betfair.append(str(input("Digite o link da Betfair: ")))
            betano.append(str(input("Digite o link da Betano: ")))
            pixbeb.append(str(input("Digite o link da Pixbet: ")))
            pinnacle.append(str(input("Digite o link da Pinnacle: ")))

        while True:
            for i in range(tamanho)
                botBasquete.botBasquete(f'{betfair[i]}{finalLinks[0]}', betano[i], pixbet[i], f'{pinnacle[i]}{finalLinks[1]}', valor, path)

