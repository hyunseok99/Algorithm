import java.util.*;

// 1. 속한 노래 재생 가장 많ㅇ느 장르 -> 많이 재생된 노래 -> 같으면 고유번호 낮은거 먼저 

// 장르 - 총 재생횟수
// 
class Solution {
    static ArrayList<Integer> ans = new ArrayList<>();

    static class Type{
        String genre;
        int total;
        Type(String genre ,int total){
            this.genre = genre;
            this.total = total;
        }
    }
    
    static class Info{
        int genre, play;
        Info(int genre, int play){
            this.genre = genre;
            this.play = play;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        getHash(genres, plays);
        
        answer = new int[ans.size()];
        for(int i=0; i<ans.size(); i++){
            answer[i] = ans.get(i);
        }
        
        return answer;
    }
    
    static void getHash(String[] genres, int[] plays){
        HashMap<String, Integer> getGenre = new HashMap<>();
        HashMap<String, Integer> myMap = new HashMap<>();
        ArrayList<ArrayList<Info>> list = new ArrayList<>();
        ArrayList<Type> type = new ArrayList<>();

        int idx = 0; // 총 장르 수

        for(int i=0; i<genres.length; i++){
            if(myMap.get(genres[i]) == null){
                myMap.put(genres[i], plays[i]);
                list.add(new ArrayList<Info>());
                list.get(idx).add(new Info(i, plays[i]));
                getGenre.put(genres[i], idx);
                idx++;
            }else{
                myMap.put(genres[i], myMap.get(genres[i]) + plays[i]);
                list.get(getGenre.get(genres[i])).add(new Info(i, plays[i]));
            }
        }

        // 총 재생 횟수 많은 순으로 장르 정렬 -> 재생 많이, 고유 번호 낮은 순으로 정렬 후 최대 2번 ans에
        for(Map.Entry<String, Integer> s: myMap.entrySet()){
            type.add(new Type(s.getKey(), s.getValue()));
        }

        type.sort((Type a, Type b) -> {
            return b.total - a.total;
        });

        // 높은 횟수의 장르당 최대 2개씩 선택
        for(Type t: type){
            int genreInt = getGenre.get(t.genre);
            ArrayList<Info> musics = list.get(genreInt);
            musics.sort((Info a, Info b) -> {
                if(a.play != b.play){
                    return b.play - a.play;
                }else{
                    return a.genre - b.genre;
                }
            });
            
            int cnt = 0;
            for(Info music: musics){
                if(cnt >= 2) break;
                ans.add(music.genre);
                cnt++;
            }
        }
    }
}