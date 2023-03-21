process.stdin.resume();
process.stdin.setEncoding('utf8');
// 自分の得意な言語で
// Let's チャレンジ！！
var reader = require('readline').createInterface({ //ストリームを行ごとに読み込む
    input: process.stdin,
    output: process.stdout
});
var n_times = 0;
var m_type = 0;
var h_height = 0;
var w_width = 0;
var count = 0;
var works = [];

var field = [];
var products = [];

// 読み込み
reader.on('line', (line) => {
    if(count == 0){
        n_times = parseInt(line.split(' ')[0]);
        m_type = parseInt(line.split(' ')[1]);
    } else if(count == 1){
        h_height = parseInt(line.split(' ')[0]);
        w_width = parseInt(line.split(' ')[1]);
    } else{
        works.push(line.split(' ').map((x) => {
            return parseInt(x);
        }));
    }
    count++;
});

// 出力
reader.on('close', () => {
    // field, productsの初期化
    for(let i = 0; i < h_height; i++){
        //配列の要素数を指定する
        field[i] = [];
        for(let j = 0; j < w_width; j++){
            field[i][j] = '.';
        }
    }
    products = new Array(m_type).fill(0);

    // 畑仕事開始
    works.forEach((work) => {
        for(let h = work[0] - 1; h < work[1]; h++){
            for(let w = work[2] - 1; w < work[3]; w++){
                // 作物を収穫する
                if(!isNaN(field[h][w]))
                    products[field[h][w] - 1]++;
                //作物を植える
                field[h][w] = work[4];
            }
        }
    });

    // 出力
    products.forEach((p) => {
        console.log(p);
    });
    field.forEach((f) => {
        console.log(f.join(''));
    });
});