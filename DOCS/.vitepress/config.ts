import { defineConfig } from 'vitepress'

export default defineConfig({
  title: "The x language",
  description: "Documentation for The x language.",

  assetsDir: 'assets',
  themeConfig: {

    logo: '/logo.png',
    siteTitle: 'XPL',
    nav: [
      { text: 'Home', link: '/' },
      {
        text: 'Learn',
        items: [
          { text: 'Style', link: '/style' },
          { text: 'Design Pattern', link: '/pattern' },
          { text: 'Code Paradigm', link: '/paradigm' },
        ]
      }
    ],

    sidebar: [
      {
        items: [
          { text: 'Language', link: '/x' },
        ]
      },
      {
        text: 'Features',
        items: [
          { text: 'Types', link: '/type' },
          { text: 'Style', link: '/style' },
          { text: 'Syntax', link: '/syntax' }
        ]
      },
      {
        text: 'Advanced',
        items: [
          { text: 'Design Pattern', link: '/pattern' },
          { text: 'Code Paradigm', link: '/paradigm' },
          { text: 'Feature Set', link: '/features' }
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/caraveo/x' }
    ]
  }
})
