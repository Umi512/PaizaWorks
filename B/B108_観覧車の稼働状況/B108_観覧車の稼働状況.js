process.stdin.resume();
process.stdin.setEncoding('utf8');
// 自分の得意な言語で
// Let's チャレンジ！！
var N_gondraNum = 0;
var M_groupNum = 0;
var A_gondra = [];
var B_group = [];
var total_gondra = [];
var count = 0;

var reader = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

// ゴンドラの制御
var countControl = function(count, N_gondraNum) {
    if(count >= N_gondraNum - 1)
        count = 0;
    else
        count++;
    return count;
};

// 計算
var calcInPeople = function(peopleNum) {
    if(peopleNum <= A_gondra[count]) { // ゴンドラに人が全員入る
        total_gondra[count] += peopleNum;
        count = countControl(count, N_gondraNum);
    } else { // ゴンドラに人が全員入らない
        total_gondra[count] += A_gondra[count];
        peopleNum -= A_gondra[count];
        count = countControl(count, N_gondraNum);
        calcInPeople(peopleNum);
    }
}

// 標準入力
reader.on('line', (line) => {
    if(count == 0) {
        N_gondraNum = parseInt(line.split(' ')[0]);
        M_groupNum = parseInt(line.split(' ')[1]);
    } else if(count <= N_gondraNum) {
        A_gondra.push(parseInt(line));
    } else {
        B_group.push(parseInt(line));
    }
    count++;
});

// 標準出力
reader.on('close', () => {
    // 初期化
    total_gondra = new Array(N_gondraNum).fill(0);
    count = 0;

    // 処理開始
    B_group.forEach((b) => {
        calcInPeople(b);
    });

    // 出力
    total_gondra.forEach((t) => {
        console.log(t);
    })
});