# studyTimeTracking

## 概要

このプログラムはシンプルな勉強時間記録や家事など行動記録プログラムです。
紙に時間を書いたり、次の日はエクセルにしたり、はたまた、どこに書いたかわからないなんてことになる悪夢は終わらせましょう。
バージョン1では、試作段階として、記録することだけにとどめて置きました。
バージョン2以降では一日の何％をその行動に使っているのか。また、今までの記録から、これから先予測される行動、例えば君が毎日本を2時間程度読んで、先週の記録は平均3.5時間、先々週の記録は1時間なら、単純計算で2時間前後読めるなどの機能を追加したいと思っています。

## 必須コンポーネント
gcc

## 動作環境
開発環境 : linux mint 22.3(2026/09/22現在)
Linuxのみでの動作を想定しており、現段階ではwindows, Mac OS, Android, iosでの動作はできません。

## コンパイルと実行方法
srcに移動して "g++ main.cpp -o mainを実行。
srcに移動して"./main"を実行。
gccをお持ちでない場合は、sudo apt install gccや、sudo pacman -S gccを行って下さい。

## 工夫点
単純なint型やchar型を使うことを避け、int型の場合はstd::int32_t or std::int16_tを使う様に、メモリリソースを意識した設計になっています。

## License
詳細は LISENCEを参照してください。

# studyTimeTracking

## Overview

This program is a simple tool for tracking study time, household chores, and other activities.
Let’s put an end to the nightmare of jotting down times on paper one day, switching to Excel the next, or even losing track of where you wrote things down.
In Version 1, as a prototype, we limited the functionality to simply recording data.

Starting with Version 2, I plan to add features such as tracking what percentage of your day is spent on a given activity. I also intend to include predictive features based on past records—for example, if you typically read for about 2 hours every day, but last week’s average was 3.5 hours and the week before that was 1 hour, the program could estimate that you’ll likely read for around 2 hours based on a simple calculation.


## System Requirements
Development Environment: Linux Mint 22.3 (as of September 22, 2026)
This application is designed to run on Linux only; at this stage, it does not support Windows, Mac OS, Android, or iOS.

## Compilation and Execution
Navigate to the folder containing the `main.cpp` file, then
g++ main.cpp -o main
./main
to run it from the terminal.
I’ll leave it up to you to handle CSV files using Office or cat.

## Design Considerations
The design is memory-efficient: it avoids using simple `int` or `char` types and instead uses `std::int32_t` or `std::int16_t` for integer values.

## License
Please refer to the LICENSE file for details.


Translated with DeepL.com (free version)
