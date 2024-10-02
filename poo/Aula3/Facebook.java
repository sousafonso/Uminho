package Aula3;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Facebook {
    private ArrayList <FBPost> posts;

    public Facebook(){
        posts = new ArrayList<>();
    }

    public Facebook(ArrayList<FBPost> posts){
        this.posts = new ArrayList<>(posts);
    }

    public int nrPosts(String user) {
        return (int) posts.stream()
                .filter(p -> p.getUtilizador().equals(user))
                .count();
    }

    public List<FBPost> postsOf(String user){
        return posts.stream().filter(u -> u.getUtilizador().equals(user)).collect(Collector.toList());
    }

    public List<FBPost> postsOf(String user, LocalDateTime inicio, LocalDateTime fim) {
    return posts.stream()
            .filter(p -> p.getUtilizador().equals(user) && 
                         p.getInstante().isAfter(inicio) &&
                         p.getInstante().isBefore(fim))
            .collect(Collectors.toList());
    }

    public FBPost getPost(int id){
        return posts.stream().filter(p->p.getId() == id)
        .findFirst()
            .orElse(null);
    }

    public void comment(FBPost post, String comentario){
        post.addComment(comentario);
    }

    public void comment(int postid, String comentario) {
        FBPost post = getPost(postid);
        if (post != null) {
            post.addComment(comentario);
        }
    }

    public void like(FBPost post){
        post.addLike();
    }

    public void like(int postid){
        FBPost p = getPost(postid);
        if (post != null) {
            post.addLike();
        }
    }

    public List<Integer> top5Comments(){
        return posts.stream()
            .sorted(Comparator.comparingInt(p -> -p.getComments().size()))
            .limit(5)
            .map(FBPost::getId) // ou .map(p -> p.getId()) 
            .collect(Collectors.toList());
    }
    
}
