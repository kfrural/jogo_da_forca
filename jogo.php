<?php

function desenhaForca($vidas) {
    switch ($vidas) {
        case 5:
            echo "Vai errar tudo\n";
            break;
        case 4:
            echo "Começou errando, vai só ladeira a baixo\n";
            break;
        case 3:
            echo "Vai errar de novo\n";
            break;
        case 2:
            echo "Quase morrendo em\n";
            break;
        case 1:
            echo "Vai perder Jaja\n";
            break;
        case 0:
            echo "Nem pra isso serve\n";
            break;
    }
}

$palavras = array("c", "python", "html", "css", "javascript", "php", "java", "swift", "go", "c#", "c++", "sql", "ruby");
$dicas = array(
    array("d1p1", "d1p2", "d1p3", "d1p4", "d1p5", "d1p6", "d1p7", "d1p8", "d1p9", "d1p10", "d1p11", "d1p12", "d1p13", "d1p14", "d1p15"),
    array("d2p1", "d2p2", "d2p3", "d2p4", "d2p5", "d2p6", "d2p7", "d2p8", "d2p9", "d2p10", "d2p11", "d2p12", "d2p13", "d2p14", "d2p15"),
    array("d3p1", "d3p2", "d3p3", "d3p4", "d3p5", "d3p6", "d3p7", "d3p8", "d3p9", "d3p10", "d3p11", "d3p12", "d3p13", "d3p14", "d3p15"),
    array("d4p1", "d4p2", "d4p3", "d4p4", "d4p5", "d4p6", "d4p7", "d4p8", "d4p9", "d4p10", "d4p11", "d4p12", "d4p13", "d4p14", "d4p15")
);

$vidas = 5;
$acertos = 0;
$palavraEscolhida = $palavras[array_rand($palavras)];
$palavraAdivinhada = str_repeat("-", strlen($palavraEscolhida));
$palavrasAdivinhadas = array_fill(0, strlen($palavraEscolhida), false);

echo "\tJOGOZINHO DA FORCAZINHA\n\n";

while ($acertos < strlen($palavraEscolhida)) {
    desenhaForca($vidas);
    echo $palavraAdivinhada . "\n";
    echo "Já acertou: " . $acertos . "\n";
    echo "Vidas até agora: " . $vidas . "\n";
    echo "Tenta ae, digita'tentar'\n";

    $letra = strtolower(trim(fgets(STDIN)));

    if ($letra === "sair") {
        echo "Correu kkk\n";
        exit;
    } elseif ($letra === "tentar") {
        echo "Digite a palavra: ";
        $palavraTentativa = trim(fgets(STDIN));
        if ($palavraTentativa === $palavraEscolhida) {
            echo "Pelo menos serve pra alguma coisa!\n";
            exit;
        } else {
            echo "Burro demais!!\n";
            $vidas = 0;
            desenhaForca($vidas);
            exit;
        }
    }

    $encontrouLetra = false;
    for ($i = 0; $i < strlen($palavraEscolhida); $i++) {
        if ($palavrasAdivinhadas[$i] || $palavraEscolhida[$i] !== $letra) {
            continue;
        }
        $palavrasAdivinhadas[$i] = true;
        $palavraAdivinhada[$i] = $letra;
        $encontrouLetra = true;
        $acertos++;
    }

    if (!$encontrouLetra) {
        $vidas--;
    }

    if ($vidas === 0) {
        echo "Burro demais 'ACEFALO'!\n";
        desenhaForca($vidas);
        exit;
    }
}

echo "Pelo menos serve pra alguma coisa!\n";
