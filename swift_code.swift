//https://programmers.co.kr/learn/challenges 문제풀이
import Foundation
import UIKit

func solution(_ clothes:[[String]]) -> Int {
    var dic = [String : Int]()
    clothes.forEach { (data) in
        guard let type = data.last else {return}
        guard let key = data.first else {return}
        if(!dic.keys.contains(key)) {
            if(dic["\(type)"] == nil) {
                dic["\(type)"] = 1
            }else {
                dic["\(type)"]! += 1
            }
        }
    }
    
    print(dic.values)
    var data_c : Int = 1
    dic.values.forEach { (d_cnt) in
        data_c = data_c * (d_cnt + 1)
    }
    return data_c - 1
}
//https://programmers.co.kr/learn/courses/30/lessons/42578/solution_groups?language=swift
//solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]])

class MusicList {
    var point:Int
    var idex:Int
    var type:String
    
    init(p : Int, i : Int, t : String) {
        self.point = p
        self.idex = i
        self.type = t
    }
}
func solution_3(_ genres:[String], _ plays:[Int]) -> [Int] {
    //1. 어떤 장르가 더 많이 재생 되었는가?
    var rankDic = [String : Int]()
    var dic = [String : [MusicList]]()
    
    for (index, genre) in genres.enumerated() {
        let temp:MusicList = MusicList(p: plays[index], i: index, t: genre)
        
        if rankDic[genre] == nil {
            rankDic[genre] = plays[index]
            dic[genre] = [temp]
        }else {
            let cnt : Int = rankDic[genre]!
            rankDic[genre] = cnt + plays[index]
            dic[genre]!.append(temp)
        }
    }
    
    let rDic = rankDic.sorted{$0.1 > $1.1}
    
    //2. 장르별 순위는 어떻게 되는가?
    //2-1. 재생횟수가 같다면 index가 낮은게 우선
    var result = [Int]()
    for r in rDic {
        let mList = dic[r.key]
        let rmList = mList?.sorted(by: {$0.point > $1.point})
        result.append((rmList?.first!.idex)!)
        
        if rmList!.count > 1 {
            result.append((rmList?[1].idex)!)
        }
    }
    
//    var playList = [String:(play: Int, music: [Int:Int])]()
//    for (index, value) in genres.enumerated() {
//            if let genre = playList[value]?.play {
//                playList[value]?.play = genre + plays[index]
//                playList[value]?.music[index] = plays[index]
//            } else {
//                playList[value] = (play: plays[index], music: [index:plays[index]])
//            }
//        }
//    print(playList)
    //3. 리스트 반환
    return result
}
//https://programmers.co.kr/learn/courses/30/lessons/42579/solution_groups?language=swift
solution_3(["classic", "classic", "classic", "pop"], [500, 150, 800, 2500])
