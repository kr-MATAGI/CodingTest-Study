"""
완주하지 못한 선수
|문제 설명|
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

|제한사항|
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

|입출력 예|
participant	completion	return
["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
["mislav", "stanko", "mislav", "ana"]	["stanko", "ana", "mislav"]	"mislav"

입출력 예 설명
예제 #1
"leo"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #2
"vinko"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #3
"mislav"는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.
"""

def solution(participant, completion):
    participant.sort()
    completion.sort()

    for i in range(len(participant)):
        try:
            if participant[i] != completion[i]:
                return participant[i]
        except:
            return participant[i]


# collections의 counter 함수 이용 사례
# counter는 컨테이너 등에서 동일한 자료가 몇개인지 세어주는 함수
# 자료형태는 딕셔너리(키, 밸류)
# +,- 연산 가능

import collections

def solution_2(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]


# hash table 이용
#   => 해쉬 테이블은 키와 밸류를 저장하는 데이터 구조
# 파이썬 딕셔너리는 해쉬 테이블로 구성되어 있음
# 고로 딕셔너리를 이용한다는 뜻

def solution_3(participant, completion):
    answer = ''
    temp = 0
    dic = {}
    for part in participant:
        dic[hash(part)] = part
        temp += int(hash(part))
    for com in completion:
        temp -= hash(com)
    answer = dic[temp]

    return answer