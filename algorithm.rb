module Algorithm
    def solution_1(babbling)
        # 옹알이 문제
        # 문제 URL : https://school.programmers.co.kr/learn/courses/30/lessons/120956
        answer = 0
        babbling_list = ['aya', 'ye', 'woo', 'ma']
        
        babbling.each do |bab|
            babbling_list.each do |list|
                if bab.include?(list)
                    bab = bab.gsub(list, " ")
                    if bab.strip.empty?
                        answer += 1
                        break
                    end
                end
            end
        end
        return answer
    end

    def solution_2(t, p)
        # 크기가 작은 부분문자열
        # 문제 URL : https://school.programmers.co.kr/learn/courses/30/lessons/147355
        answer = 0
        cnt_str = []
        (0..t.length).each do |i|
            cnt_str << t[i..i+(p.length-1)]
            break if i+p.length == t.length
        end
        answer = cnt_str.select{|c| c.to_i <= p.to_i}.count
        return answer
    end
end