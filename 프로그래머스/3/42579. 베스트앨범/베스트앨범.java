// import java.util.*;

// // 1. 속한 노래 재생 가장 많ㅇ느 장르 -> 많이 재생된 노래 -> 같으면 고유번호 낮은거 먼저 

// // 장르 - 총 재생횟수
// // 
// class Solution {
//     static ArrayList<Integer> ans = new ArrayList<>();

//     static class Type{
//         String genre;
//         int total;
//         Type(String genre ,int total){
//             this.genre = genre;
//             this.total = total;
//         }
//     }
    
//     static class Info{
//         int genre, play;
//         Info(int genre, int play){
//             this.genre = genre;
//             this.play = play;
//         }
//     }
    
//     public int[] solution(String[] genres, int[] plays) {
//         int[] answer = {};
//         getHash(genres, plays);
        
//         answer = new int[ans.size()];
//         for(int i=0; i<ans.size(); i++){
//             answer[i] = ans.get(i);
//         }
        
//         return answer;
//     }
    
//     static void getHash(String[] genres, int[] plays){
//         HashMap<String, Integer> getGenre = new HashMap<>();
//         HashMap<String, Integer> myMap = new HashMap<>();
//         ArrayList<ArrayList<Info>> list = new ArrayList<>();
//         ArrayList<Type> type = new ArrayList<>();

//         int idx = 0; // 총 장르 수

//         for(int i=0; i<genres.length; i++){
//             if(myMap.get(genres[i]) == null){
//                 myMap.put(genres[i], plays[i]);
//                 list.add(new ArrayList<Info>());
//                 list.get(idx).add(new Info(i, plays[i]));
//                 getGenre.put(genres[i], idx);
//                 idx++;
//             }else{
//                 myMap.put(genres[i], myMap.get(genres[i]) + plays[i]);
//                 list.get(getGenre.get(genres[i])).add(new Info(i, plays[i]));
//             }
//         }

//         // 총 재생 횟수 많은 순으로 장르 정렬 -> 재생 많이, 고유 번호 낮은 순으로 정렬 후 최대 2번 ans에
//         for(Map.Entry<String, Integer> s: myMap.entrySet()){
//             type.add(new Type(s.getKey(), s.getValue()));
//         }

//         type.sort((Type a, Type b) -> {
//             return b.total - a.total;
//         });

//         // 높은 횟수의 장르당 최대 2개씩 선택
//         for(Type t: type){
//             int genreInt = getGenre.get(t.genre);
//             ArrayList<Info> musics = list.get(genreInt);
//             musics.sort((Info a, Info b) -> {
//                 if(a.play != b.play){
//                     return b.play - a.play;
//                 }else{
//                     return a.genre - b.genre;
//                 }
//             });
            
//             int cnt = 0;
//             for(Info music: musics){
//                 if(cnt >= 2) break;
//                 ans.add(music.genre);
//                 cnt++;
//             }
//         }
//     }
// }

// 우선순위: 장르 -> 노래 -> 고유 번호 낮은 
import java.util.*;
import java.io.*;

class Solution{
    
    // genre : tot_plays 
    Map<String, Integer> cnt_map = new HashMap<>();
    Map<String, Integer> idx_map = new HashMap<>();
    
    class Genre {
        String genre;
        int tot_plays;
        public Genre(String genre, int tot_plays){
            this.genre = genre;
            this.tot_plays = tot_plays;
        }
    }
    
    class Song implements Comparable<Song>{
        int idx; // 노래 고유 idx 
        int plays;
        public Song(int idx, int plays){
            this.idx = idx;
            this.plays = plays;
        }
        
        @Override
        public int compareTo(Song tmp){
            // max-heap
            return Integer.compare(tmp.plays, plays);
        }
    }
    public int[] solution(String[] genres, int[] plays) {
        int[] answer;
        ArrayList<Integer> answer_list = new ArrayList<>();
        int genre_idx = 0;
        PriorityQueue<Song>[] pq = new PriorityQueue[100];// 장르 최대 99개
        for(int i=0; i<100; i++){
            pq[i] = new PriorityQueue<>();
        }
        // 필요: 장르별 총 재생 수 , 특정 장르의 각각의 재생 수 
        for(int i=0; i<genres.length; i++){
            String genre = genres[i];
            int play = plays[i];
            Song tmp_song = new Song(i, play);

            // 장르 idx
            if(!cnt_map.containsKey(genre)){
                cnt_map.put(genre, play);
                idx_map.put(genre, genre_idx);
                pq[genre_idx].add(tmp_song);
                genre_idx++;
            }else{
                cnt_map.put(genre, cnt_map.get(genre) + play);
                pq[idx_map.get(genre)].add(tmp_song);
            }
        }
        // 장르별 재생 횟수를 위한 pq 
        PriorityQueue<Genre> g_pq = new PriorityQueue<>(
            (a, b) -> b.tot_plays - a.tot_plays);

        for(Map.Entry<String, Integer> entry:cnt_map.entrySet()){
            g_pq.add(new Genre(entry.getKey(), entry.getValue()));
        }

        while(!g_pq.isEmpty()){
            Genre cur_genre = g_pq.poll();
            int g_idx =  idx_map.get(cur_genre.genre);
            int cnt = 0;
            while(!pq[g_idx].isEmpty() && cnt < 2){
                Song cur_song = pq[g_idx].poll();
                System.out.println(" song_idx: " + cur_song.idx);
                answer_list.add(cur_song.idx);
                cnt++;
            }
        }
        
        answer = new int[answer_list.size()];
        for(int i=0; i<answer_list.size(); i++){
            answer[i] = answer_list.get(i);
        }
        return answer;
    }
    
}

