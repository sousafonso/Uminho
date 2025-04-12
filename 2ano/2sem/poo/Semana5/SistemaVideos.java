package Semana5;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Map;

import Semana3.Video;

public class SistemaVideos {
    Map <String, Video> videos;

    public SistemaVideos() {
        this.videos = null;
    }

    public SistemaVideos(Map<String, Video> videos) {
        this.videos = videos;
    }

    public Map<String, Video> getVideos() {
        return videos;
    }

    public void setVideos(Map<String, Video> videos) {
        this.videos = videos;
    }

    public void addVideo(Video v){
        videos.put(v.getNome(), v);
    }

    public Video getVideo(String codVideo){
        return videos.get(codVideo);
    }

    public void removeVideo(String codVideo){
        videos.remove(codVideo);
    }

    public void addLike(String codVideo){
        Video v = videos.get(codVideo);
        if (v != null) {
            v.setLikes(v.getLikes() + 1);
        }

        System.out.println("Like added to video: " + codVideo);
    }

    public String topLikes(){
        String topVideo = null;
        int maxLikes = 0;

        for (Map.Entry<String, Video> entry : videos.entrySet()) {
            Video video = entry.getValue();
            if (video.getLikes() > maxLikes) {
                maxLikes = video.getLikes();
                topVideo = entry.getKey();
            }
        }

        return topVideo;
    }

    public String topLikes(LocalDate dinicial, LocalDate dfinal){
        String topVideo = null;
        int maxLikes = 0;

        for (Map.Entry<String, Video> entry : videos.entrySet()) {
            Video video = entry.getValue();
            if (video.getData().isAfter(dinicial) && video.getData().isBefore(dfinal) && video.getLikes() > maxLikes) {
                maxLikes = video.getLikes();
                topVideo = entry.getKey();
            }
        }

        return topVideo;
    }

    public Video videoMaisLongo(){
        String topVideo = null;
        LocalTime maxDuracao = null;

        for (Map.Entry<String, Video> entry : videos.entrySet()) {
            Video video = entry.getValue();
            if (video.getDuracao().isAfter(maxDuracao)) {
                maxDuracao = video.getDuracao();
                topVideo = entry.getKey();
            }
        }

        return videos.get(topVideo);
    }

}

