//
//  ContentView.swift
//  MyBitmovinPlayer
//
//  Created by Ewan Chelley on 18/12/2024.
//

import SwiftUI
import Combine
import BitmovinPlayer


struct ContentView: View {
    
    var body: some View {
        VStack {
            let player = bmPlayer()
            VideoPlayerView(
                player: player
            )
            .onReceive(player.events.on(PlayerEvent.self)) { (event: PlayerEvent) in
                dump(event, name: "[Player Event]", maxDepth: 1)
            }
            .onReceive(player.events.on(SourceEvent.self)) { (event: SourceEvent) in
                dump(event, name: "[Source Event]", maxDepth: 1)
            }
        }
        .padding()
    }
    
    func bmPlayer() -> Player {
        let player = PlayerFactory.createPlayer()
        
        guard let streamUrl = URL(string: "https://bitmovin-a.akamaihd.net/content/MI201109210084_1/m3u8s/f08e80da-bf1d-4e3d-8899-f0f6155f6efa.m3u8"),
                     let posterUrl = URL(string: "https://bitmovin-a.akamaihd.net/content/MI201109210084_1/poster.jpg") else {
                   fatalError("Invalid URL")
               }
        
        let sourceConfig = SourceConfig(url: streamUrl, type: .hls)
        sourceConfig.posterSource = posterUrl
        
        let source = SourceFactory.createSource(from: sourceConfig)
        
        player.load(source: source)
        
        return player
    }
}



#Preview {
    ContentView()
}
