#pragma once

#include "../RenderStage.h"

namespace cc {
namespace pipeline {

class RenderFlow;
class RenderView;
class RenderBatchedQueue;
class RenderInstancedQueue;
class RenderAdditiveLightQueue;
class RenderQueue;
class PlanarShadowQueue;

class CC_DLL ForwardStage : public RenderStage {
public:
    static const RenderStageInfo &getInitializeInfo();

    ForwardStage();
    ~ForwardStage();

    virtual bool initialize(const RenderStageInfo &info) override;
    virtual void activate(RenderPipeline *pipeline, RenderFlow *flow) override;
    virtual void destroy() override;
    virtual void render(RenderView *view) override;

protected:
    RenderQueueDescList _renderQueueDescriptors;
    vector<RenderQueue *> _renderQueues;

private:
    static RenderStageInfo _initInfo;

    PlanarShadowQueue *_planarShadowQueue = nullptr;
    RenderBatchedQueue *_batchedQueue = nullptr;
    RenderInstancedQueue *_instancedQueue = nullptr;
    RenderAdditiveLightQueue *_additiveLightQueue = nullptr;
    gfx::Rect _renderArea;
    gfx::ColorList _clearColors = {{0, 0, 0, 1.0f}};
};

} // namespace pipeline
} // namespace cc
